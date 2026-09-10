
{
description = "A basic library written in C++ for generating placeholder Lorem Ipsum text.";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
        flake-utils.url = "github:numtide/flake-utils";
    };

    outputs =
        {
            self,
            nixpkgs,
            flake-utils,
        }:
        flake-utils.lib.eachDefaultSystem (
            system:
            let
                pkgs = import nixpkgs { inherit system; };
            in
            {
                packages.default = pkgs.stdenv.mkDerivation
                {
                    pname = "lipsum-cpp";
                    version = "0.5.5";
                    src = ./.;
                    nativeBuildInputs = with pkgs; [
                        cmake
                        ninja
                        pkg-config
                        doxygen
                    ];

                    cmakeFlags = [
                        "-GNinja"
                        "-DCMAKE_BUILD_TYPE=Release"
                        "-DLPSM_BUILD_EXAMPLES=ON"
                        "-DLPSM_FORMAT=OFF"
                        "-DLPSM_TIDY=OFF"
                        "-DLPSM_BUILD_CLI=ON"
                        "-DLPSM_BUILD_DOCS=ON"
                        "-DLPSM_BUILD_SAMPLE=OFF"
                        "-DLPSM_BUILD_VERSION=OFF"
                        
                    ];

                };

                devShells.default = pkgs.mkShell {
                    packages = with pkgs; [
                        gcc
                        gnumake
                        cmake
                        ninja
                        python3
                        doxygen
                        clang-tools
                        emscripten
                        gdb
                        dpkg
                        rpm
                        cpio
                        fpm
                        libxml2
                        json_c
                        zlib
                        pkg-config
                    ];

                    shellHook = ''
                        VENV_DIR=$(mktemp -d -t python3-venv-XXXXXX)
                        trap "rm -rf $VENV_DIR" EXIT
                        python3 -m venv "$VENV_DIR"
                        source "$VENV_DIR/bin/activate"
                        export PIP_PREFIX="$VENV_DIR"
                        pip3 install quom
                        pip3 install ./src/lipsumpy
                        unset SOURCE_DATE_EPOCH
                    '';
                };
            }
        );
}
