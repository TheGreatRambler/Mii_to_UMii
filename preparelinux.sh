sudo apt-get install pkg-config -y
sudo apt-get install libfmt-dev=7.1.3+ds1-5 -y
sudo apt-get install libcurl4-openssl-dev=7.38.0-4+deb8u16 -y
# Prepare submodules
cd lib/cryptopp
git submodule update --init --recursive
make static CPPFLAGS="-DNDEBUG -g2 -Os -pthread -pipe"
cd ../../
cd lib/oead
git submodule update --init --recursive
mkdir bin
cd bin
cmake -G "Unix Makefiles" ..
make CPPFLAGS="-Os"
cd ../../../
cd lib/ZXing
git submodule update --init --recursive
mkdir bin
cd bin
cmake -G "Unix Makefiles" -DBUILD_WRITERS=OFF -DBUILD_EXAMPLES=OFF -DBUILD_BLACKBOX_TESTS=OFF -DCMAKE_BUILD_TYPE=Release ..
make
cd ../../../