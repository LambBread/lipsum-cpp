# Maintainer: LambBread <LambBread@github.com>
pkgname=lipsum-cpp
pkgver=0.5.0
pkgrel=1
pkgdesc="A basic library written in C++ for generating placeholder Lorem Ipsum text."
arch=('x86_64' 'aarch64')
url="https://github.com/LambBread/lipsum-cpp"
license=('0BSD')
depends=()
makedepends=('cmake' 'base-devel' 'doxygen')
provides=('lipsum-cpp')
source=("${pkgname}-master.tar.gz::https://github.com/LambBread/${pkgname}/archive/master.tar.gz")
sha256sums=('SKIP')

build() {
    cd "${pkgname}-master"
    cmake -S . -B build \
        -DLPSM_FORMAT=OFF -DLPSM_BUILD_VERSION=OFF -DLPSM_BUILD_SAMPLE=OFF \
        -DLPSM_BUILD_DOCS=ON -DLPSM_BUILD_STATIC=ON \
        -DLPSM_BUILD_CWRAPPER=ON -DLPSM_BUILD_CLI=ON \
        -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
    cmake --build build
} 

package() {
    cd "${pkgname}-master"
    DESTDIR="${pkgdir}" cmake --install build
} 
