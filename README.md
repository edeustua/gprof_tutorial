# Playing with gprof

<https://sourceware.org/binutils/docs/gprof/>

How to read the gprof report:
<https://ftp.gnu.org/old-gnu/Manuals/gprof-2.9.1/html_chapter/gprof_5.html>

## Building Qcore
Qcore

`cmake -DCMAKE_CXX_FLAGS=-pg -DCMAKE_EXE_LINKER_FLAGS=-pg -DCMAKE_SHARED_LINKER_FLAGS=-pg -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Debug -DENTOS_USE_MOBML=OFF -DENTOS_USE_TBB=OFF ../`

# Intel oneAPI
<https://software.intel.com/content/www/us/en/develop/tools/oneapi/base-toolkit.html>
