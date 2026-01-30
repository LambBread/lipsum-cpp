# lipsum-cpp scripts

There are three files in this folder: 

- [`split.py`](./split.py)
- [`lipsum.txt`](./lipsum.txt)
- [`format.sh`](./format.sh)

`split.py` is used to count the words in the sample `lipsum.txt` and form it into an `std::vector<std::string>`, stored in [`src/lipsum/sample.inl`](../src/lipsum/sample.inl). `format.sh` is a Bash script which runs clang-format on the source files, assuming you are at the root directory.
