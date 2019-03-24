import random
def rand_clusters(k,n,r, a,b,c,d):
    """return k clusters of n points each in random disks of radius r
where the centers of the disk are chosen randomly in [a,b]x[c,d]"""
    clusters = []
    for _ in range(k):
        x = a + (b-a)*random()
        y = c + (d-c)*random()
        clusters.extend(rand_cluster(n,(x,y),r))
    return clusters
rand_clusters(3,1000,100,1,1,1,1);
