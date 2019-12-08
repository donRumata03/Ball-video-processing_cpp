import os
import time

def sub_strings(path, path0):
    return path[len(path0):]

def counter(path0):
    tree = os.walk(path_0)
    all_files = []
    for d, dirs, files in tree:
        for f in files:
            path = os.path.join(d,f)
            all_files.append(path)


    for file in all_files:
        good_file = False
        for extension in code_file_extensions:
            if file[-len(extension):] == extension:
                good_file = True
                break
        if not good_file:
            continue
        s = open(file, "r").read()
        spl = s.split("\n")
        print(sub_strings(file, path_0), ":", len(s), "symbols, ", len(spl), "lines")
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




#######     For user:   #################
code_file_extensions = [".py", ".cpp"]  #
path_0 = "D:\\Projects\\Video_anal"
data_path = "D:\\Projects\\Video_anal\\"     #
#########################################

total_sum = 0
lines_sum = 0
non_blank_lines_num = 0






