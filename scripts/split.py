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
    lorem_ipsum = count_unique_words("lipsum.txt")
    cat_ipsum = count_unique_words("catipsum.txt")
    dog_ipsum = count_unique_words("dogipsum.txt")
    corpo_ipsum = count_unique_words("corporateipsum.txt")
    def write_array(array, name, f):
        f.write("static constexpr std::array<const char*, " + str(len(array)) + "> " 
                + name + " = {")
        for word in array:
            f.write(f"\"{word}\",\n")
        f.write("};\n")

    with open("../src/lipsum/core/sample.inl", "w") as file:
        file.write("""/** 
 * @file lipsum/core/sample.inl
 * 
 * @brief File containing all of the words used by lipsum::Source
 * 
 * This file contains constexpr arrays of strings,
 * each a word in the original samples.
 * 
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_CORE_SAMPLE_INL
#define LIPSUM_CORE_SAMPLE_INL

""")
        write_array(lorem_ipsum, "LIPSUM_VEC", file)
        write_array(cat_ipsum, "CAT_IPSUM", file)
        write_array(dog_ipsum, "DOG_IPSUM", file)
        write_array(corpo_ipsum, "CORPO_IPSUM", file)
        file.write("#endif")

