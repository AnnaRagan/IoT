mkdir -p build && \
cd build && \
rm -f CMakeCache.txt && \
cmake -DTARGET=RASPBERRY -DPATH=$1 .. && \
make