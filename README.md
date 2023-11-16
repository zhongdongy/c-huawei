## Build

### Windows

Assumes using Cygwin (gcc should be installed already), open Cygwin Terminal:

```bash
mkdir -p target/libs
gcc -std=c11 -c -o target/libs/sorting.o libs/sorting.c
gcc -std=c11 -c -o target/libs/utils.o libs/utils.c
gcc -std=c11 -I. -o target/main.exe target/libs/sorting.o target/libs/utils.o main.c
./target/main.exe
```

Or include build and run in one line:

```bash
gcc -std=c11 -c -o target/libs/sorting.o libs/sorting.c \
  && gcc -std=c11 -c -o target/libs/utils.o libs/utils.c \
  && gcc -std=c11 -I. -o target/main.exe target/libs/sorting.o target/libs/utils.o main.c \
  && ./target/main.exe
```

Or simply this code:

```bash
mkdir -p target/libs
find libs/ -iregex '.*\.c' -execdir basename -s ".c" {} + | xargs -i sh -c 'src=libs/{}.c; dst=target/libs/{}.o; gcc -std=c11 -c -o "$dst" "$src"'
find libs/ -iregex '.*\.c' -execdir basename -s ".c" {} + | xargs printf 'target/libs/%s.o ' | xargs -d\@ printf 'gcc -std=c11 -I. -o target/main.exe %s main.c' | sh
./target/main.exe
```

There is also a script called `run.sh` that can do all above.

### Windows (Cygwin + CMake + Make + GCC)

You will need to install Cygwin (or mingw), then have cmake, make and packages from Cygwin preinstalled.

Use this one line code:

```bash
cmake "CMakeLists.txt" && make && ./target/huawei
```