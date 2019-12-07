import os

dir0 = "D:\\Libraries\\PycharmProjects\\Podgonyator\\Video+Photo\\cpp"
dir1 = "D:\\Libraries\\PycharmProjects\\Podgonyator\\Video+Photo\\cpp\\Circling"
dir2 = "D:\\Libraries\\PycharmProjects\\Podgonyator\\Video+Photo\\cpp\\Graph_bulider"

lsdir = os.listdir(dir0)
lsdir.extend(os.listdir(dir1))
lsdir.extend(os.listdir(dir2))

total_sum = 0
lines_sum = 0
non_blank_lines_num = 0

for file in lsdir:
    good_file = False
    if file[-3:] == ".py" or file[-4:] == ".cpp":
        good_file = True
    if not good_file:
        continue
    if file[-3:] == ".py":
        print("hi from python:", file)
    try:
        s = open(dir0 + "\\" + file, "r").read()
    except:
        try:
            s = open(dir1 + "\\" + file, "r").read()
        except:
            s = open(dir2 + "\\" + file, "r").read()
    spl = s.split("\n")
    print(file, ":", len(s), "symbols, ", len(spl), "lines")
    total_sum += len(s)
    lines_sum += len(spl)
    for l in spl:
        if l != "":
            non_blank_lines_num += 1


print("*********************")
print("Total number of symbols in project:")
print(total_sum)
print("Total number of lines in project:")
print(lines_sum)
print("Average line length:")
print(round(10 * total_sum / lines_sum) / 10)
print("Average non-blank line length:")
print(round(10 * total_sum / non_blank_lines_num) / 10)
print("Percent of blank lines:")
print(round(1000 * (1 - (non_blank_lines_num / lines_sum))) / 10, "%")

