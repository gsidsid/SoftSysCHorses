#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt


def rand_clusters(within_cluster_stddev, between_cluster_variance, num_clusters, points_per_cluster):
    '''Return a dataset of clustered points.

    @param within_cluster_stddev the standard deviation within each cluster.
    @param between_cluster_variance the standard deviation between each cluster.
    @param num_clusters the amount of clusters
    @param points_per_cluster the amount of points in each cluster.
    '''
    return np.vstack(
        [np.random.multivariate_normal(
            # Generate random cluster center
            np.random.normal([0, 0], between_cluster_variance),
            # Covariance of within-cluster spread
            [[between_cluster_variance, 0], [0, between_cluster_variance]],
            points_per_cluster)
         for _ in range(num_clusters)])


# Test the function
RAND_POINTS = rand_clusters(0.0001, 100, 3, 10000)

F, AX = plt.subplots()
AX.plot(RAND_POINTS[:, 0], RAND_POINTS[:, 1], '.')

np.savetxt("random_clusters_10000.csv", RAND_POINTS, delimiter=",")

plt.show()
