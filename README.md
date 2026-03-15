## Setup

```sh
[compiler] cmake --preset <preset>
```

Use clang/gcc or default.
See presets in `CMakePresets.json`.

## Build

```sh
cmake --build --preset <preset>
```

The binary will be in `build/<preset>`.

## Test

```sh
ctest --preset <preset>
```

## Example:

```sh
CC=gcc CXX=g++ cmake --preset release
cmake --build --preset release
ctest --preset release
```
