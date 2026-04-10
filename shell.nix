{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  # nativeBuildInputs brings in the tools you need at development time
  nativeBuildInputs = with pkgs; [
    gcc          # The C++ compiler (provides g++)
    gdb          # The GNU Debugger
    clang-tools  # Provides 'clangd' for VS Code IntelliSense and 'clang-format'
  ];

  # shellHook runs automatically when you enter the nix-shell
  shellHook = ''
    echo "========================================"
    echo "   C++ Development Environment Loaded   "
    echo "========================================"
    echo "Compiler: $(g++ --version | head -n 1)"
    echo "Debugger: $(gdb --version | head -n 1)"
    echo "LSP:      clangd is ready for VS Code"
    echo "========================================"
  '';
}