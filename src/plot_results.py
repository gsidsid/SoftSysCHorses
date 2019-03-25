#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt

POINTS = np.genfromtxt("other_points.csv", delimiter=",")
CENTERS = np.genfromtxt("cluster_centers.csv", delimiter=",")
CLUSTERS = []
for _ in range(len(CENTERS)):
    CLUSTERS.append([])

print(CLUSTERS)

for point in POINTS:
    CLUSTERS[np.argmin(np.linalg.norm(CENTERS - point, axis=1))].append(point)

for i, _ in enumerate(CLUSTERS):
    CLUSTERS[i] = np.array(CLUSTERS[i])
    if (not CLUSTERS[i].size):
        CLUSTERS[i] = CLUSTERS[i].reshape(0, 2)

F, AX = plt.subplots()
for cluster in CLUSTERS:
    AX.plot(cluster[:, 0], cluster[:, 1], '.')

AX.plot(CENTERS[:, 0], CENTERS[:, 1], 'bs')
F.savefig("result.png")

plt.show()
