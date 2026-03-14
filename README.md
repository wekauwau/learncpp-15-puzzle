## Setup:

```sh
[compiler] cmake --preset <preset> -DBOARD_WIDTH=<width> -DBOARD_HEIGHT=<height>
```

Use clang/gcc or default.
See presets in `CMakePresets.json`.
`<width>` and `<height>` must be > 1.

## Build:

```sh
cmake --build --preset <preset>
```

The binary will be in `build/<preset>/src/main`.

## Example:

Using gcc in release mode. Playing in 4x4 board.

```sh
CC=gcc CXX=g++ cmake --preset release -DBOARD_WIDTH=4 -DBOARD_HEIGHT=4
```
