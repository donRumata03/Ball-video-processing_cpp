from matplotlib import pyplot as plt
file = open("D:\\Libraries\\PycharmProjects\\Podgonyator\\Video+Photo\\cpp\\res\\data_for_graphing\\error_func_test.txt", "r").read().strip()

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
