mkdir -p build && \
cd build && \
rm -f CMakeCache.txt && \
cmake -DTARGET=DOCKER -DPATH=$1 .. && \
make