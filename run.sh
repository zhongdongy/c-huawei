#!/usr/bin/sh

rm -rf ./target/libs &&
  echo ">> [AUTO] Build targets cleaned"
mkdir -p ./target/libs &&
  echo ">> [AUTO] Target directory created"
find libs/ -iregex '.*\.c' -execdir basename -s ".c" {} + | xargs -i sh -c 'src=libs/{}.c; dst=target/libs/{}.o; gcc -g -std=c11 -c -o "$dst" "$src"' &&
  echo ">> [AUTO] Build libs complete"
find libs/ -iregex '.*\.c' -execdir basename -s ".c" {} + | xargs printf 'target/libs/%s.o ' | xargs -d\@ printf 'gcc -g -std=c11 -I. -o target/main.exe %s main.c' | sh &&
  echo ">> [AUTO] Linkage complete, generated content: ./target/main.exe"

echo -e '>> [AUTO] Running program ./target/main.exe:\n'
./target/main.exe
