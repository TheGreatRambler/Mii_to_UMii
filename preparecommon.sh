# Prepare submodules
cd lib/cryptopp
git submodule update --init --recursive
make static CPPFLAGS="-DNDEBUG -g2 -Os -pthread -pipe"
cd ../../
cd lib/oead
git submodule update --init --recursive
mkdir -p build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make CPPFLAGS="-Os"
cd ../../
cd ZXing
git submodule update --init --recursive
mkdir -p ../ZXing_build
cd ../ZXing_build
cmake -G "Unix Makefiles" -DBUILD_WRITERS=OFF -DBUILD_EXAMPLES=OFF -DBUILD_BLACKBOX_TESTS=OFF -DCMAKE_BUILD_TYPE=Release ../ZXing
make
cd ../../