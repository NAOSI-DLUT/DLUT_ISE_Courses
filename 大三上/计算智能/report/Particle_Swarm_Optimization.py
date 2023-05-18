"""
Authored by Chen Shi
Created on Dec 1st
"""

import numpy as np
import matplotlib.pyplot as plt

# number of particles
NUM = 100 
# number of iterations
T = 100
# learning coefficient C1, C2
# [0.4, 2]
# {2, 2}, {1.6, 1.8}, {1.6, 2}
C1 = 1.6
C2 = 2
# inertial coefficient W
# [0.4, 2]
# 0.9, 1.2
W = 0.9
# set xi's bound
X_MIN = 0
X_MAX = 15
# set of max fitness    
MAX_FITNESS = []                                                                     
# set of min fitness              
MIN_FITNESS = []  

# target function
def function(x1, x2, x3):
	return 2*x1**2 - 3*x2**2 - 4*x1 + 5*x2 + x3

# function clamp() is used to limit the range of results
def clamp(n, minn, maxn):
    n = np.maximum(n, minn)
    n = np.minimum(n, maxn)
    return n

# define a class to save the attributes
class PSO(object):
    # max_or_min: max == 1, min == -1
    # individual_size: number of individuals(particles)
    # max_steps: number of iterations
    def __init__(self, max_or_min, individual_size=NUM, max_steps=T):
        self.max_or_min = max_or_min
        self.individual_size = individual_size
        self.max_steps = max_steps
        # dimension
        self.dim = 3
        # x's bound
        self.x_bound = [X_MIN, X_MAX]
        # location
        self.x = np.random.randint(self.x_bound[0],self.x_bound[1]+1, size=(NUM, self.dim))
        # velocity
        self.v = np.random.rand(self.individual_size, self.dim)
        # calculate fitness
        fitness = self.calculate_fitness(self.x, self.max_or_min)
        # explore the best position of one individual
        self.p = self.x
        # Explore the best position of global individuals
        self.pg = self.x[np.argmax(fitness)]
        # best fitness of one individual
        self.individual_best_fitness = fitness
        # best fitness of global individuals
        self.global_best_fitness = np.max(fitness)
        # append into the sets
        if self.max_or_min == 1:
            MAX_FITNESS.append(self.global_best_fitness)
        elif self.max_or_min == -1:
            MIN_FITNESS.append(-self.global_best_fitness)

    # calculate fitness
    def calculate_fitness(self, x, max_or_min):
        x1 = x[:,0]
        x2 = x[:,1]
        x3 = x[:,2] 
        pred = function(x1, x2, x3)
        if max_or_min == 1:
            return pred
        elif max_or_min == -1:
            return -pred

    # PSO function
    def PSO_function(self, max_or_min):
        for _ in range(self.max_steps):
            # according to the formula
            # r1 and r2 are random numbers, increasing the search randomness
            r1 = np.random.rand(self.individual_size, self.dim)
            r2 = np.random.rand(self.individual_size, self.dim)
            
            # update velocity and C1, C2
            self.v  = W*self.v+C1*r1*(self.p-self.x)+C2*r2*(self.pg-self.x)
            minn = [[self.x_bound[0]]*self.dim]*self.individual_size
            maxn =   [[self.x_bound[1]]*self.dim]*self.individual_size
  
            # limit the bound
            self.x = clamp(self.v + self.x, minn, maxn)
            
            # calculate fitness
            fitness = self.calculate_fitness(self.x, max_or_min)
            
            # update one individual
            update_id = np.greater(self.individual_best_fitness, fitness)
            self.p[update_id] = self.x[update_id]
            self.individual_best_fitness[update_id] = fitness[update_id]
            
            # update global best fitness
            if np. max(fitness) > self.global_best_fitness:
                self.pg = self.x[np.argmax(fitness)]
                self.global_best_fitness = np.max(fitness)
            # print(' best fitness: %.5f, mean fitness: %.5f' % (-self.global_best_fitness, -np.mean(fitness)))
            
            # append into the sets
            if max_or_min == 1:
                MAX_FITNESS.append(np.max(fitness))
            elif max_or_min == -1:
                MIN_FITNESS.append(-np.max(fitness))
            
 
if __name__ == "__main__":
    # get max fitness
    pso_max = PSO(1)
    pso_max.PSO_function(1)
    print("max fitness: %.5f" % (np.max(MAX_FITNESS)))

    # get min fitness
    pso_min = PSO(-1)
    pso_min.PSO_function(-1)
    print("min fitness: %.5f" % (np.min(MIN_FITNESS)))

    # show results by graph
    plt.plot(MAX_FITNESS)
    plt.title("Max fitness, C1 = " + str(C1) + ", C2 = " + str(C2) + ", W = " + str(W))
    plt.show()

    plt.plot(MIN_FITNESS)
    plt.title("Min fitness, C1 = " + str(C1) + ", C2 = " + str(C2) + ", W = " + str(W))
    plt.show()