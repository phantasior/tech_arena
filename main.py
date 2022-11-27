# Просто строит график

import matplotlib.pyplot as plt

f = open("./tests/03.txt")

n, c1, c2 = [float(i) for i in f.readline().split()]
coords = []

n = int(n)

for i in range(n):
    x, y = [float(i) for i in f.readline().split()]
    coords.append((x, y))

coords.append(coords[0]) #repeat the first point to create a 'closed loop'

xs, ys = zip(*coords) #create lists of x and y values

plt.figure()
plt.plot(xs,ys) 
plt.show()

f.close()