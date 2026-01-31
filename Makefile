# Makefile for Linux
#
# This is a Makefile targeting Linux, intended for development which 
# calls CMake and handles packaging of new releases.
BUILD_DIR := build
PKG_DIR := bin
SRC_DIR := src
DOCS_DIR := docs
CMAKE_GENERATOR := Ninja
BUILD_TYPE := Release
CMAKE_OPTS := -DLPSM_BUILD_STATIC=ON -DLPSM_BUILD_CWRAPPER=ON \
			  -DLPSM_BUILD_DOCS=ON -DLPSM_BUILD_EXAMPLES=ON -DLPSM_BUILD_SAMPLE=ON \
			  -DLPSM_BUILD_JSBIND=ON -DLPSM_FORMAT=ON

.PHONY: all clean build configure em_configure em_build format amalgamate pkg total_clean

all: build

configure:
	cmake -S . -B $(BUILD_DIR) -G "$(CMAKE_GENERATOR)" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) $(CMAKE_OPTS)

em_configure:
	emcmake cmake -S . -B $(BUILD_DIR) -G "$(CMAKE_GENERATOR)" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) $(CMAKE_OPTS)

build: configure
	cmake --build $(BUILD_DIR)

em_build: em_configure
	cmake --build $(BUILD_DIR)

format:
	cmake --build $(BUILD_DIR) --target format

amalgamate:
	mkdir -p $(PKG_DIR)
	quom $(SRC_DIR)/lipsum.hpp $(PKG_DIR)/lipsum.hpp

pkg: clean em_build format amalgamate
	rm $(BUILD_DIR)/$(SRC_DIR)/jsbind/cmake_install.cmake
	rm -rf $(BUILD_DIR)/$(SRC_DIR)/jsbind/CMakeFiles
	7z a -tzip -r -mx=9 $(PKG_DIR)/lipsum-jsbind.zip $(BUILD_DIR)/$(SRC_DIR)/jsbind

clean:
	rm -rf $(BUILD_DIR)

total_clean: clean
	rm -rf $(PKG_DIR)
	rm -rf $(DOCS_DIR)
