{ pkgs ? (
    let
      sources = import ./nix/sources.nix;
    in
    import sources.nixpkgs {
      overlays = [ ];
    }
  )
}:

pkgs.mkShell {
  packages = with pkgs; [
    gnumake
    cmake
    clang
    clangStdenv
    python3
  ];
}
