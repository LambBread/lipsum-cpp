# Makefile for Linux
#
# This is a Makefile targeting Linux, intended for development which 
# calls CMake and handles packaging of new releases.
BUILD_DIR := build
PKG_DIR := bin
SRC_DIR := src
DOCS_DIR := docs
EXAMPLES_DIR := examples
CMAKE_GENERATOR ?= Ninja
BUILD_TYPE ?= Release
CMAKE_OPTS ?= -DLPSM_BUILD_STATIC=ON -DLPSM_BUILD_CWRAPPER=ON \
			  -DLPSM_BUILD_DOCS=ON -DLPSM_BUILD_EXAMPLES=ON \
			  -DLPSM_BUILD_JSBIND=ON

.PHONY: all clean build configure em_configure em_build format amalgamate \
	pkg full_clean sample quick_pkg pkg_ version tidy

all: build

configure:
	cmake -S . -B $(BUILD_DIR) -G "$(CMAKE_GENERATOR)" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) $(CMAKE_OPTS)

em_configure:
	emcmake cmake -S . -B $(BUILD_DIR) -G "$(CMAKE_GENERATOR)" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) $(CMAKE_OPTS)

build: configure
	cmake --build $(BUILD_DIR)

em_build: em_configure
	cmake --build $(BUILD_DIR)

version:
	cmake --build $(BUILD_DIR) --target version
	cmake --build $(BUILD_DIR) --target format

tidy:
	clang-tidy src/lipsum_h.cpp -- -DLIPSUM_BUILD_STATIC
	clang-tidy src/lipsum_static.cpp

format:
	cmake --build $(BUILD_DIR) --target format

sample:
	cmake --build $(BUILD_DIR) --target sample
	cmake --build $(BUILD_DIR) --target format

amalgamate:
	mkdir -p $(PKG_DIR)
	quom $(SRC_DIR)/lipsum.hpp $(PKG_DIR)/lipsum.hpp
	quom $(SRC_DIR)/lipsum.h $(PKG_DIR)/lipsum.h
	quom $(SRC_DIR)/lipsum_h.cpp $(PKG_DIR)/lipsum_h.cpp

pkg_:
	cp $(BUILD_DIR)/$(SRC_DIR)/jsbind/lipsum* $(BUILD_DIR)/examples/
	cp $(BUILD_DIR)/$(SRC_DIR)/jsbind/lipsum* $(PKG_DIR)/
	cp $(EXAMPLES_DIR)/JSBinding.html $(BUILD_DIR)/examples/
	rm $(BUILD_DIR)/examples/Source.*
	7z a -tzip -r -mx=9 lipsum-pkg.zip $(PKG_DIR)
	
quick_pkg: em_configure version format tidy em_build amalgamate pkg_

pkg: clean quick_pkg

clean:
	rm -rf $(BUILD_DIR)

full_clean: clean
	rm -rf $(PKG_DIR)
	rm -rf $(DOCS_DIR)
