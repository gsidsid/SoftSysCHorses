#!/usr/bin/env python3
import timeit
import numpy as np
from scipy.cluster.vq import kmeans, whiten

POINTS = whiten(np.genfromtxt("random_clusters_10000.csv", delimiter=","))
WHITENED = whiten(POINTS)
time = timeit.timeit(lambda: kmeans(WHITENED, 3), number=1)
print(time)
