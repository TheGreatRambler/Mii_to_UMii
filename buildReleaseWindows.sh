make clean
make -B BUILD=release ARCH=64

rm -rf release

mkdir -p release/bin
rm release/bin/miitoumii.exe
cp bin/*.exe release/bin
cp bin/*.dll release/bin
strip -s release/bin/miitoumii.exe

rm miitoumii-windows-64bit.zip
zip -r miitoumii-windows-64bit.zip release
rm -r release