#!/bin/python3
# Basic script that splits a source "lorem ipsum" into the unique
# words it uses. It outputs it in C++ syntax to be put in lipsum.inl.
import re
import sys
from collections import Counter

def count_unique_words(filename):
    with open(filename, 'r', encoding='utf-8') as f:
        text = f.read()
    words = re.findall(r'\b\w+\b', text.lower())
    word_counts = Counter(words)
    unique_words = list(word_counts.keys())
    return unique_words

if __name__ == "__main__":
    unique_words = count_unique_words("lipsum.txt")
    with open("../src/lipsum.inl", "w") as file:
        file.write("""/** @file lipsum.inl
 * 
 * @brief File containing all of the words used by lipsum::GenerateWord()
 *
 * This file is for inclusion inside a function, containing a vector of strings,
 * each a word in the original sample lipsum.txt
 * 
 * @author LambBread from github.com
 */
static std::vector<std::string> lipsumVec = {""")
        for word in unique_words:
            file.write(f"\"{word}\",\n")
        file.write("};")

