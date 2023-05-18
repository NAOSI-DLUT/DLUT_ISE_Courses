import numpy as np
import matplotlib.pyplot as plt
import math
import random
import copy

# The function of encoding
def EncodeGenes(numGenes, integerbit, decimalbit, gene):
    for i in range(numGenes):
        integer_n = random.randint(0, integerbit)
        decimal_n = random.randint(0, decimalbit)

        if integer_n > 0:
            for j in range(integer_n):
                pos = random.randint(0, integerbit-1)
                gene[i][pos] = 1
        if decimal_n > 0:
            for j in range(decimal_n):
                pos = random.randint(integerbit, integerbit+decimalbit-1)
                gene[i][pos] = 1
    return gene

# The function of decoding
def DecodeGenes(numGenes, integerbit, decimalbit, gene):
    toFloat = []
    for i in range(numGenes):
        sum = 0
        for j in range(integerbit+decimalbit):
            pownum = (integerbit-1)-j
            sum += gene[i][j]*math.pow(2, pownum)

        toFloat.append(sum)

    return toFloat

# The function for fitness
def Fitness(value):
    x1 = value[0]
    x2 = value[1]
    x3 = value[2]
    fit = 2*x1*x1-3*x2*x2-4*x1+5*x2+x3

    return fit

# The function of creating the roulette
# Compared to traditional roulette, I improved the benchmark. Weights were calculated using # the minimum fitness of each batch of gene as the reference value.
def CreateRoulette(numGenes, mode, genes, values, fitnesses):
    if mode == 1:  # Mode for 1, which means the maximum value is evaluated
        total = numGenes
        sumfitness = 0
        i = 0
        while i < total:
            # Delete the individuals whose fitness is less than 0 or value more than 15
            if fitnesses[i] <= 0 or max(values[i]) > 15:
                del genes[i]
                del values[i]
                del fitnesses[i]
                i = i-1
                total = total-1
            i = i+1

        standard = min(fitnesses)
        i = 0
        while i < len(genes):
            sumfitness += (fitnesses[i]-standard)
            i = i+1

        boundary = [0]
        sumweight = 0
        i = 0
        while i < total:  # Create the lower bound of the roulette
            weight = (fitnesses[i]-standard)/sumfitness
            sumweight += weight
            boundary.append(sumweight)
            i = i+1
        boundary[-1] = 1.0  # Create the upper bound of the roulette

    else:  # Mode for 0, which means the minimum value is evaluated
        total = numGenes
        sumfitness = 0
        i = 0
        while i < total:
            # Delete the individuals whose fitness is more than 0 or value more than 15
            if fitnesses[i] <= 0 or max(values[i]) > 15:
                del genes[i]
                del values[i]
                del fitnesses[i]
                i = i-1
                total = total-1
            i = i+1

        standard = max(fitnesses)
        i = 0
        while i < len(genes):
            sumfitness += math.fabs(fitnesses[i]-standard)
            i = i+1

        boundary = [0]
        sumweight = 0
        i = 0
        while i < total:  # Create the lower bound of the roulette
            absfitness = math.fabs(fitnesses[i]-standard)
            weight = absfitness/sumfitness
            sumweight += weight
            boundary.append(sumweight)
            i = i+1
        boundary[-1] = 1.0  # Create the upper bound of the roulette

    return boundary, genes, values, fitnesses

#  The Roulette function to screen individuals with high fitness
def SelectFromRoulette(selecttimes, boundary, genes, values, fitnesses):
    bin = len(boundary)
    allSelect = list(range(bin-1))
    waitForSelect = []
    for i in range(selecttimes):
        ran = np.random.rand(1)

        index = -1

        for j in range(bin):
            if ran[0] > boundary[j] and ran[0] <= boundary[j+1]:
                index = j
            if index != -1:
                waitForSelect.append(index)
                break

    waitForSelect = list(set(waitForSelect))  # Remove duplicate individuals from the list
    for i in waitForSelect:
        allSelect.remove(i)

    genes = [genes[i] for i in range(0, len(genes), 1) if i not in allSelect]
    values = [values[i] for i in range(0, len(values), 1) if i not in allSelect]
    fitnesses = [fitnesses[i] for i in range(0, len(fitnesses), 1) if i not in allSelect]

    return genes, values, fitnesses

# The function of chromosomal cross: a randomly generated cross of two points. For the two # generated random points, the crossover mode needs to be generated.
def CrossGene(numGenes, genes, totalbit, crosstimes = 3, RateOfModel = 0.7):
    for i in range(numGenes):
        x1 = genes[i][0]
        x2 = genes[i][1]
        x3 = genes[i][2]
        x = [x1, x2, x3]
        for j in range(crosstimes):
            indexa = 0
            indexb = 0
            while indexa == indexb:
                indexa = random.randint(0, crosstimes-1)
                indexb = random.randint(0, crosstimes-1)

            posa = 0
            posb = 0
            while posa == posb:
                posa = random.randint(0, totalbit-1)
                posb = random.randint(0, totalbit-1)
            if posa < posb:
                posa, posb = posb, posa

            modepro = np.random.rand(1)  # Select the crossover mode randomly
            if modepro >= RateOfModel:
                mode = 1  # Intersect the outside part
            else:
                mode = 0  # Intersect the inside part

            tempx1 = x[indexa]
            tempx2 = x[indexb]
            tempx = copy.deepcopy(tempx1)
            if mode == 0:
                tempx1[posa:posb+1] = tempx2[posa:posb+1]
                tempx2[posa:posb+1] = tempx[posa:posb+1]
                x[indexa] = tempx1
                x[indexb] = tempx2
            if mode == 1:
                tempx1[0:posa+1] = tempx2[0:posa+1]
                tempx1[posb:totalbit] = tempx2[posb:totalbit]
                tempx2[0:posa+1] = tempx[0:posa+1]
                tempx2[posb:totalbit] = tempx[posb:totalbit]
                x[indexa] = tempx1
                x[indexb] = tempx2

        x = np.array(x)
        genes[i] = x

    return genes

# The function for chromosome random variation
def MutateGene(numGenes, genes, totalbit, genesnumber = 3):
    for i in range(numGenes):
        index = random.randint(0, genesnumber-1)
        pos = random.randint(0, totalbit-1)

        if genes[i][index][pos] == 0:
            genes[i][index][pos] = 1
        else:
            genes[i][index][pos] = 0

    return genes

# The function for breeding
def Inherit(numGenes, genes, totalbit, genesnumber = 3):
    for i in range(numGenes):
        father = -1
        mother = -1
        while father == mother:
            father = random.randint(0, numGenes-1)
            mother = random.randint(0, numGenes-1)

        fathergenes = random.randint(1, genesnumber-1)
        mothergenes = genesnumber - fathergenes

        allindex = list(range(genesnumber))
        fatherindex = []
        motherindex = []
        childx1 = np.zeros((totalbit), dtype=int)
        childx2 = np.zeros((totalbit), dtype=int)
        childx3 = np.zeros((totalbit), dtype=int)
        child = np.array([childx1, childx2, childx3])
        if mothergenes == 1:
            motherindex.append(random.randint(0, genesnumber-1))
            fatherindex = copy.deepcopy(allindex)
            fatherindex.remove(motherindex[0])
            child[motherindex[0]] = genes[mother][motherindex[0]]
            child[fatherindex[0]] = genes[father][fatherindex[0]]
            child[fatherindex[1]] = genes[father][fatherindex[1]]
            child = np.array(child)
            genes.append(child)
        else:
            fatherindex.append(random.randint(0, genesnumber-1))
            motherindex = copy.deepcopy(allindex)
            motherindex.remove(fatherindex[0])
            child[fatherindex[0]] = genes[father][fatherindex[0]]
            child[motherindex[0]] = genes[mother][motherindex[0]]
            child[motherindex[1]] = genes[mother][motherindex[1]]
            child = np.array(child)
            genes.append(child)

    return genes

if __name__ == '__main__':
    Integer_Bit = 4  # The number of digits in the integral part of genes
    Decimal_Bit = 8  # The number of digits in the decimal part of genes
    Total_Bit = Integer_Bit+Decimal_Bit  # The total number of digits of genes
    Genes_Number = 3  # The number of genes contained in each individual
    Initial_Genes = 100  # The number of individuals in a primary population
    Iteration = 100  # The number of iterations
    RateOfStay = 3  # The ratio of population retention
    RateOfSelect = 1.1  # The ratio of select times
    TheMAX = True
    TheMin = False

    # Record the extreme value after each iteration
    Record_x1 = []
    Record_x2 = []
    Record_x3 = []
    Record_y = []

    # Set the iteration Mode, Mode=1 for the maximum value and Mode=0 for the minimum value
    if TheMAX is True and TheMin is False:
        Mode = 1
    elif TheMAX is False and TheMin is True:
        Mode = 0

    allGene = []  # Store the genotypes of all the individuals in the population
    for i in range(Initial_Genes):
        x1 = np.zeros((Total_Bit), dtype=int)
        x2 = np.zeros((Total_Bit), dtype=int)
        x3 = np.zeros((Total_Bit), dtype=int)
        gene = np.array([x1, x2, x3])
        allGene.append(gene)

    for i in range(Initial_Genes):
        allGene[i] = EncodeGenes(Genes_Number, Integer_Bit, Decimal_Bit, allGene[i])

    it = 0
    while it < Iteration:
        allValue = []  # Store the phenotypes of all individuals in the population
        allFitness = []  # Store the fitness of all individuals in the population

        # Find the phenotype of the gene
        Num_Genes = len(allGene)
        for i in range(Num_Genes):
            value = DecodeGenes(Genes_Number, Integer_Bit, Decimal_Bit, allGene[i])
            value = np.array(value)
            allValue.append(value)

        # Assess the fitness of individuals in the population
        Num_Genes = len(allGene)
        for i in range(Num_Genes):
            y = Fitness(allValue[i])
            allFitness.append(y)

        # The natural selection
        Num_Genes = len(allGene)
        boundary, allGene, allValue, allFitness = CreateRoulette(Num_Genes, Mode, allGene, allValue, allFitness)
        Num_Genes = len(allGene)
        select_times = math.ceil(Num_Genes*RateOfSelect)
        allGene, allValue, allFitness = SelectFromRoulette(select_times, boundary, allGene, allValue, allFitness)

        # Reduce the population and keep it constant
        if len(allGene) > Initial_Genes*RateOfStay:
            allGene = allGene[0:Initial_Genes]
            allValue = allValue[0:Initial_Genes]
            allFitness = allFitness[0:Initial_Genes]

        # Update recorders
        if Mode == 1:
            Index = allFitness.index(max(allFitness))
            Record_x1.append(allValue[Index][0])
            Record_x2.append(allValue[Index][1])
            Record_x3.append(allValue[Index][2])
            Record_y.append(allFitness[Index])
        else:
            Index = allFitness.index(min(allFitness))
            Record_x1.append(allValue[Index][0])
            Record_x2.append(allValue[Index][1])
            Record_x3.append(allValue[Index][2])
            Record_y.append(allFitness[Index])

        # chromosomal crossing
        Num_Genes = len(allGene)
        allparentGene = allGene
        allparentGene = CrossGene(Num_Genes, allparentGene, Total_Bit)

        # Chromosomal variation
        Num_Genes = len(allparentGene)
        allparentGene = MutateGene(Num_Genes, allparentGene, Total_Bit)

        # Population generation
        Num_Genes = len(allparentGene)
        allparentGene = Inherit(Num_Genes, allparentGene, Total_Bit)
        allGene = allGene+allparentGene

        # Update iterator
        it = it+1

    if Mode == 1:
        MAX_Index = Record_y.index(max(Record_y))
        x1 = Record_x1[MAX_Index]
        x2 = Record_x2[MAX_Index]
        x3 = Record_x3[MAX_Index]
        y = Record_y[MAX_Index]
        print(x1)
        print(x2)
        print(x3)
        print(y)
    else:
        MIN_Index = Record_y.index(min(Record_y))
        x1 = Record_x1[MIN_Index]
        x2 = Record_x2[MIN_Index]
        x3 = Record_x3[MIN_Index]
        y = Record_y[MIN_Index]
        print(x1)
        print(x2)
        print(x3)
        print(y)

    # Data visualization
    plt.figure()
    plt.plot(Record_x1, 'r', Record_x2, 'b', Record_x3, 'g')
    plt.xlabel('Iterations')
    plt.ylabel('Value')
    plt.legend(['x1', 'x2', 'x3'], loc='upper left')
    plt.figure()
    plt.plot(Record_y, 'r')
    plt.xlabel('Iterations')
    plt.ylabel('Value')
    plt.legend(['y'], loc='best')
    plt.show()
