# lipsum-cpp Python wrapper

Usage is very similar to C++ by importing module `lipsum_cpp`. Sometimes, you may need to explicitly convert
a generated string to Python `str`. For an example, see [`examples/PyWrapper.py`](../../examples/PyWrapper.py).

To install, build lipsum-cpp as a shared library with C wrapper support and copy the generated library
to `src/lipsumpy/lipsum_cpp`. From there, you can install it with `pip`.
