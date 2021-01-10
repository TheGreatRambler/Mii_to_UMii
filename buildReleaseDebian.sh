make clean
make -B BUILD=release ARCH=64 SYSTEM=debian

mkdir -p miitoumii_debian/usr/bin
rm miitoumii_debian/usr/bin/miitoumii
cp bin/miitoumii miitoumii_debian/usr/bin
strip -s miitoumii_debian/usr/bin/miitoumii

dpkg-deb --build miitoumii_debian miitoumii-debian-64bit.deb