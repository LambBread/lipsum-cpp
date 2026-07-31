{ pkgs ? import <nixpkgs> {} };

pkgs.mkShell
{
    buildInputs = with pkgs; [
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
    '';
}
