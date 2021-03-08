# Using gprof with C++
`gprof` allows one to profile a C/C++ or Fortran application. It provides you
with a report of the execution timings of the various functions and procedures
of your code. A good starting place to learn how to use `gprof` is its manual
which is hosted at <https://sourceware.org/binutils/docs/gprof/>.

## Quick start
In order to profile an application using `gprof` one must first compile with
target program with profiling enabled. This is done in the `gcc` suite by
appending the flag `-pg` to the compilation and linking of the program. For
example, for a C/C++ program, one would make sure that
```makefile
CFLAGS := -pg
LDFLAGS := -pg
```
are enabled.

Once compiled, the resulting executable produces a file `gmon.out` after
exiting. This binary file contains the timing information of the program and can
be read by using the `gprof` command like so:
```bash
$ gprof [EXECUTABLE] > profile.gprof
```
in the directory containing `gmon.out` which will produce a human-readable file
`profile.gprof`. Details on how to read this file can be found here
<https://sourceware.org/binutils/docs/gprof/Output.html#Output>.

There is an example of how to use `gprof` in this repository.

## Building Qcore
To build `qcore` with profiling flags, one must configure `cmake` with the `-pg`
flags, and because `qcore` is linked with an intermediate library, shared
library building must be disabled. This can be achieved as so:
```bash
cmake -DCMAKE_CXX_FLAGS=-pg \
      -DCMAKE_EXE_LINKER_FLAGS=-pg \
      -DCMAKE_SHARED_LINKER_FLAGS=-pg \
      -DBUILD_SHARED_LIBS=OFF \
      -DCMAKE_BUILD_TYPE=Debug \
      -DENTOS_USE_MOBML=OFF \
      -DENTOS_USE_TBB=OFF \
      [QCORE_PATH]
```
Once `cmake` has been configured, compilation is carried out normally.


# Using a mutex for random number generation

# Intel oneAPI
<https://software.intel.com/content/www/us/en/develop/tools/oneapi/base-toolkit.html>

# Mutex
<https://software.intel.com/content/www/us/en/develop/documentation/advisor-user-guide/top/appendix/adding-parallelism-to-your-program/replacing-annotations-with-intel-threading-building-blocks-intel-tbb-code/intel-threading-building-blocks-intel-tbb-simple-mutex-example.html>
