import random
import csv
from numpy import vstack,array
from numpy.random import rand
import numpy
radius = 200
rangeX = (0, 2500)
rangeY = (0, 2500)
qty = 1000
deltas = set()
for x in range(-radius, radius+1):
    for y in range(-radius, radius+1):
        if x*x + y*y <= radius*radius:
            deltas.add((x,y))

randPoints = []

i = 0
while i<qty:
    x = random.randrange(*rangeX)
    y = random.randrange(*rangeY)
    randPoints.append((x,y))
    i += 1

randPoints_float = vstack((rand(150,2) *2500 ,rand(150,2)*2500))

print (randPoints)
numpy.savetxt("random_float.csv", randPoints_float, delimiter=",")

numpy.savetxt("random_int.csv", randPoints, delimiter=",")
