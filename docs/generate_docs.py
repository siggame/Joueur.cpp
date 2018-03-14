import os
import os.path
import subprocess
import shutil
from datetime import date
import sys

def run(*args, **kwargs):
    error_code = subprocess.call(*args, **kwargs)
    if error_code != 0: # an error happened
        sys.exit(error_code)

temp_path = "./temp"
if not os.path.exists(temp_path):
    os.mkdir(temp_path)

shutil.copyfile("Doxyfile", os.path.join(temp_path, "Doxyfile"))
shutil.copyfile("../README.md", os.path.join(temp_path, "README.md"))
shutil.copyfile("footer.html", os.path.join(temp_path, "footer.html"))

files = []
for root, dirnames, filenames in os.walk("../games/"):
    for filename in filenames:
        path = os.path.join(root, filename)
        if 'impl' in path or filename == 'CMakeLists.txt':
            continue
        files.append(path)

for path in files:
    #shutil.copyfile(os.path.join(game_path, name), os.path.join(temp_path, name))
    temp_path_for_file = os.path.normpath(os.path.join(temp_path, path.replace("../", '')))
    dir_path = os.path.dirname(temp_path_for_file)

    if not os.path.exists(dir_path):
        os.makedirs(dir_path)

    with open(path, "r") as f:
        lines = f.readlines()
        # for each line check if it is a class declaration, if so remove trailing `_`s
        with open(temp_path_for_file, "w") as temp_file:
            for i, line in enumerate(lines):
                if line.startswith("class"): # remove trailing underscores
                    line = line.rstrip()
                    split = line.split(" ")
                    for j, word in enumerate(split):
                        if word[-1] == "_":
                            split[j] = word[0:len(word)-1] # cutoff the trailing `_`
                    line = " ".join(split) + "\n"
                temp_file.write(line)

for extra in ["base_object.cpp", "base_object.hpp",
              "base_ai.cpp", "base_ai.hpp"]:
    shutil.copyfile(os.path.join("..", "joueur/src/", extra), os.path.join(temp_path, extra))

run(["doxygen"], shell=True, cwd=temp_path)

output_path = "./output"
if os.path.isdir(output_path):
    shutil.rmtree(output_path)
shutil.copytree(os.path.join(temp_path, "docs", "html"), output_path)

shutil.rmtree(temp_path)
