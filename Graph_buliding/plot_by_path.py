import sys
from matplotlib import pyplot as plt

path = sys.argv[1]

file = open(path, "r").read().strip()

data = file.split("\n")

xs = []
ys = []

for point in data:
    x, y = map(float, point.split(" "))
    xs.append(x)
    ys.append(y)

print(min(ys), xs[ys.index(min(ys))])

plt.plot(xs, ys)
plt.show()
