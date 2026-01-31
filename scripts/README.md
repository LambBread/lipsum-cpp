# lipsum-cpp scripts

There are three files in this folder: 

- [`split.py`](./split.py)
- [`lipsum.txt`](./lipsum.txt)
- [`server.sh`](./server.sh)

`split.py` is used to count the words in the sample `lipsum.txt` and form it into an `std::vector<std::string>`, stored in [`src/lipsum/sample.inl`](../src/lipsum/sample.inl). `server.sh` is a script that runs an HTTP server in `docs/html` and `build/examples`.
