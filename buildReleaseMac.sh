make clean
make -B BUILD=release ARCH=64

mkdir -p miitoumii_mac.app/Contents/MacOS
rm miitoumii_mac.app/Contents/MacOS/miitoumii
cp bin/miitoumii miitoumii_mac.app/Contents/MacOS
strip -s miitoumii_mac.app/Contents/MacOS/miitoumii

dylibbundler -od -b -x miitoumii_mac.app/Contents/MacOS/miitoumii -d miitoumii_mac.app/Contents/libs/

rm miitoumii-mac-64bit.zip
zip -r miitoumii-mac-64bit.app.zip miitoumii_mac.app