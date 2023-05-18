#!/usr/bin/python
# -*- coding: utf-8 -*-
import random
import numpy as np
import matplotlib.pyplot as plt

pop_size = 100
variable_num = 3
dec_min_val = (0, 0, 0)
dec_max_val = (15, 15, 15)
pop_x = np.zeros((pop_size, variable_num))
pop_v = np.zeros((pop_size, variable_num))
p_best = np.zeros((pop_size, variable_num))


def init_population(pop_size, variable_num, dec_min_val, dec_max_val, pop_x, pop_v, p_best):
    for i in range(pop_size):
        for j in range(variable_num):
            pop_x[i][j] = random.uniform(dec_min_val[j], dec_max_val[j])
            pop_v[i][j] = random.uniform(0, 1)
        p_best[i] = pop_x[i]


max_gen = 100
w = 0.6
c1 = 2
c2 = 2
g_best = np.zeros((1, variable_num))
result = []


def fitness(s):
    x1 = s[0]
    x2 = s[1]
    x3 = s[2]
    y = 2 * x1 ** 2 - 3 * x2 ** 2 - 4 * x1 + 5 * x2 + x3
    return y


if __name__ == '__main__':
    init_population(pop_size, variable_num, dec_min_val, dec_max_val, pop_x, pop_v, p_best)
    temp = -1

    for i in range(pop_size):
        fit = fitness(p_best[i])
        if fit > temp:
            g_best = p_best[i]
            temp = fit

    for i in range(max_gen):
        for j in range(pop_size):
            # update individual
            pop_v[j] = w * pop_v[j] + c1 * random.uniform(0, 1) * (p_best[j] - pop_x[j]) + \
                        c2 * random.uniform(0, 1) * (g_best - pop_x[j])
            pop_x[j] = pop_x[j] + pop_v[j]
            for k in range(variable_num):  # limit range
                if pop_x[j][k] < dec_min_val[k]:
                    pop_x[j][k] = dec_min_val[k]
                if pop_x[j][k] > dec_max_val[k]:
                    pop_x[j][k] = dec_max_val[k]
            #  Update p_best and g_best
            if fitness(pop_x[j]) > fitness(p_best[j]):
                p_best[j] = pop_x[j]
            if fitness(pop_x[j]) > fitness(g_best):
                g_best = pop_x[j]
        result.append(fitness(g_best))
        print("Generation %d: %.4f" % (i, fitness(g_best)))

    #  Visualization
    plt.figure(1)
    plt.title("Figure")
    plt.xlabel("count", size=14)
    plt.ylabel("value", size=14)
    plt.plot(result, color='b', linewidth=2)
    plt.show()
