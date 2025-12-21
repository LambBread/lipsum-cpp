# lipsum-cpp scripts

There are three files in this folder: `split.py`, `lipsum.txt`, and `format.sh`. `split.py` is used to count the words in the sample `lipsum.txt` and form it into an `std::vector<std::string>`, stored in [`src/lipsum.inl`](../src/lipsum.inl). `format.sh` is a Bash script which runs clang-format on the source files, assuming the current working directory is in this directory.
