{ pkgs ? import <nixpkgs> { } }:
pkgs.mkShell {
  nativeBuildInputs = with pkgs.buildPackages; [
    libgcc
    gdb
    valgrind
    splint

    simavr
    pkgsCross.avr.buildPackages.gcc # avr-gcc  
  ];
  shellHook =
    ''
      clear
      alias gcc="gcc -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all -Wextra"
      gcc --version
      echo "dev env set-up for CMSC216"
    '';
}
