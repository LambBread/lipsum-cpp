# lipsum-cpp scripts

There are four files in this folder: 

- [`lipsum.txt`](./lipsum.txt)
- [`server.sh`](./server.sh)
- [`split.py`](./split.py)
- [`version.cmake`](./version.cmake)

`split.py` is used to count the words in the sample `lipsum.txt` and form it into an `std::array<const char*>`, 
stored in [`src/lipsum/sample.inl`](../src/lipsum/sample.inl). `server.sh` is a script that runs an HTTP server 
in `docs/html` and `build/examples`. `version.cmake` creates header files storing the current version of lipsum-cpp, 
and is called by [`cmake/version.cmake`](../cmake/version.cmake).
