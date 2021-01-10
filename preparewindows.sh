pacman -S pkg-config -y --needed
pacman -S mingw-w64-x86_64-fmt -y --needed
pacman -S mingw-w64-x86_64-curl -y --needed
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