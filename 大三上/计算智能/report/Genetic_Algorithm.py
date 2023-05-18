"""
Authored by Chen Shi
Created on Dec 1st
"""

import matplotlib.pyplot as plt
import numpy as np

# length of gene
GENE_LENGTH = 4
# number of individuals
NUM = 100
# probability of crossover
# [0.4, 0.99]
# 0.4, 0.8
P_C = 0.4
# probability of mutation
# [0.001, 0.1]
# 0.05, 0.1
P_M = 0.1
# number of generations
T = 100
# set of max fitness
MAX_FITNESS = []
# set of min fitness
MIN_FITNESS = []
# whether it is based on the square of fitness
IS_SQUARE = 1


# target funtion
def function(x1, x2, x3):
	return 2*x1**2 - 3*x2**2 - 4*x1 + 5*x2 + x3


# the calculation of the fitness
"""
求最大适应度: max_or_min == 1
求最小适应度: max_or_min == -1
"""
def calculate_fitness(individuals, max_or_min):

    # [:, m:n]: get the data within the range of [m, n)
    x1_binary = individuals[:, 0:4]
    x2_binary = individuals[:, 4:8]
    x3_binary = individuals[:, 8:12]

    # binary to decimal
    # The number of each xi is 100
    # one group (x1, x2, x3) constitutes an individual
    # total 100 individuals
    x1 = x1_binary.dot(2 ** np.arange(GENE_LENGTH))
    x2 = x2_binary.dot(2 ** np.arange(GENE_LENGTH))
    x3 = x3_binary.dot(2 ** np.arange(GENE_LENGTH))

    # get max fitness:
    if max_or_min == 1:
        # 100 individuals in total p
        # red gets 100 values (100 dimensional vector)
        pred = function(x1, x2, x3)
        # append into the set of max fitness
        MAX_FITNESS.append(pred.max())
        # print("current max fitness: ", np.max(MAX_FITNESS))
        # set each result in pred >= 0
        return (pred - pred.min())
    # get min fitness:
    elif max_or_min == -1:
        pred = -function(x1, x2, x3)
        MIN_FITNESS.append(-pred.max())
        # print("current min fitness: ", np.min(MIN_FITNESS))
        # set each result in pred >= 0
        return (pred - pred.min())
    

# crossover
def crossover(individuals):
    # to save intermediate individuals
    temp_individuals = []

    # each ia in the parent set will be traversed once
    # randomly select ib to make pairs with ia
    for ia in individuals:
        temp = ia
        if np.random.rand() < P_C:
            # randomly select ib
            ib = individuals[np.random.randint(NUM)]
            # randomly select crossover points
            cross_points = np.random.randint(low=0, high=GENE_LENGTH*3)
            temp[cross_points:] = ib[cross_points:]
        # save the results into the temp set
        temp_individuals.append(temp)
    # return the results to the mutation function
    return temp_individuals


# mutation
def mutation(temp_individuals):
    # each individual in temp set may mutate based on the probability
    for temp in temp_individuals:
        if np.random.rand() < P_M:
            mutate_point = np.random.randint(0, GENE_LENGTH)
            temp[mutate_point] = temp[mutate_point]^1
    return temp_individuals


# roulette selection
"""
if is proportional to the square of fitness: is_square == 1
"""
def roulette_selection(individuals, fitness, is_square):

    # square
    if is_square == 1:
        fitness = np.square(fitness)

    # follow the roulette to determine the next generation
    # generate an array with dimensions of 100 from 0 to 99
    # the probability of each dimension being selected is based on the p of the corresponding position
    idx = np.random.choice(np.arange(NUM), size=NUM, replace=True, p=(fitness)/(fitness.sum()))
    return individuals[idx]


# GA function
"""
max_or_min: calculate max fitness or min fitness
is_square: whether is proportional to the square of fitness
"""
def GA_function(max_or_min, is_square):
    # generation 0
    individuals = np.random.randint(2, size=(NUM, GENE_LENGTH * 3))

    # calculate fitness
    fitness = calculate_fitness(individuals, max_or_min)

    # 1~T generations
    for _ in range(T):
        # roulette
        individuals = roulette_selection(individuals, fitness, is_square)
        # crossover & mutation
        individuals = np.array(mutation(crossover(individuals)))
        # calculate fitness
        fitness = calculate_fitness(individuals, max_or_min)
    
    # print max or min fitness
    if max_or_min == 1:
        print("max fitness: %.5f" % (np.max(MAX_FITNESS)))
    
    elif max_or_min == -1:
        print("min fitness: %.5f" % (np.min(MIN_FITNESS)))


if __name__ == "__main__":
    
    # get max fitness
    GA_function(1, IS_SQUARE)

    # get min fitness
    GA_function(-1, IS_SQUARE)

    # show the result by graph
    plt.plot(MAX_FITNESS)
    # set titles
    plt.title("Max fitness, P_C = " + str(P_C) + ", P_M = " + str(P_M) + 
                (", square" if IS_SQUARE == 1 else ", no square"))
    plt.show()

    plt.plot(MIN_FITNESS)
    plt.title("Min fitness, P_C = " + str(P_C) + ", P_M = " + str(P_M) + 
                (", square" if IS_SQUARE == 1 else ", no square"))
    plt.show()
    