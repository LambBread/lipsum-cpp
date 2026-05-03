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
			  -DLPSM_BUILD_JSBIND=ON -DLPSM_BUILD_CLI=ON

.PHONY: all clean build configure em_configure em_build format amalgamate \
	pkg full_clean sample quick_pkg pkg_ version tidy help install cpack

all: build ## Build the project normally.

configure: ## Configure the project normally.
	cmake -S . -B $(BUILD_DIR) -G "$(CMAKE_GENERATOR)" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) $(CMAKE_OPTS)

em_configure: ## Configure the project under Emscripten.
	emcmake cmake -S . -B $(BUILD_DIR) -G "$(CMAKE_GENERATOR)" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) $(CMAKE_OPTS)

build: configure ## Build the project normally.
	cmake --build $(BUILD_DIR)

em_build: em_configure ## Build the project under Emscripten.
	cmake --build $(BUILD_DIR)

version: ## Run the versioning script.
	cmake --build $(BUILD_DIR) --target version
	cmake --build $(BUILD_DIR) --target format

tidy: ## Run clang-tidy.
	clang-tidy src/lipsum_h.cpp -- -DLIPSUM_BUILD_STATIC
	clang-tidy src/lipsum_static.cpp

format: ## Run clang-format.
	cmake --build $(BUILD_DIR) --target format

sample: ## Run the script that creates the standard lorem-ipsum sample, along with clang-format.
	cmake --build $(BUILD_DIR) --target sample
	cmake --build $(BUILD_DIR) --target format

amalgamate: ## Form the main source files into single file variants.
	mkdir -p $(PKG_DIR)
	quom $(SRC_DIR)/lipsum.hpp $(PKG_DIR)/lipsum.hpp
	quom $(SRC_DIR)/lipsum.h $(PKG_DIR)/lipsum.h
	quom $(SRC_DIR)/lipsum_h.cpp $(PKG_DIR)/lipsum_h.cpp

pkg_: ## Run the final packaging steps, namely copying certain examples and compressing the final archive.
	cp $(BUILD_DIR)/$(SRC_DIR)/jsbind/lipsum* $(BUILD_DIR)/$(EXAMPLES_DIR)/
	cp $(BUILD_DIR)/$(SRC_DIR)/jsbind/lipsum* $(PKG_DIR)/
	cp $(EXAMPLES_DIR)/JSBinding.html $(BUILD_DIR)/$(EXAMPLES_DIR)/
	7z a -tzip -r -mx=9 lipsum-pkg.zip $(PKG_DIR)
	
quick_pkg: em_configure version format tidy em_build amalgamate pkg_ ## Build an Emscripten build of the project, running the versioning script, clang-format, clang-tidy, amalgamation, and final packaging steps.

pkg: clean quick_pkg ## Clean the build directory, then make a build with all steps of quick_pkg.

clean: ## Remove the build directory.
	rm -rf $(BUILD_DIR)

full_clean: clean ## Remove the build directory, packaging directory, and generated docs directory.
	rm -rf $(PKG_DIR)
	rm -rf $(DOCS_DIR)

install: clean build ## Install lipsum-cpp to the default install location.
	cmake --install build

cpack: clean build ## Run CPack and generate packages.
	cd $(BUILD_DIR) && cpack

help: ## Show this help.
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
