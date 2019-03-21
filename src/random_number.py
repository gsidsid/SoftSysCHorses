import random
import csv
from numpy import vstack,array
from numpy.random import rand
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
#excluded = set()# excludes all points within radius of previous points
#to increase randomness
i = 0
while i<qty:
    x = random.randrange(*rangeX)
    y = random.randrange(*rangeY)
    #if (x,y) in excluded: continue
    randPoints.append((x,y))
    i += 1

    #excluded.update((x+dx, y+dy) for (dx,dy) in deltas)
randPoints = vstack((rand(150,2) + array([.5,.5]),rand(150,2)))

print (randPoints)

import csv

item_length = len(randPoints[0])

with open('test.csv', 'wb') as test_file:
  file_writer = csv.writer(test_file)
  for i in range(item_length):
    file_writer.writerow([x[i] for x in randPoints])
