# Project Zvum

A C game prototype built with SDL3. The current development preview implements a main menu with bitmap buttons, basic input handling, and a 1280 × 720 window.

## Current features

- SDL3 application callbacks and rendering.
- Play and Settings button textures with centered placement.
- Mouse hit detection for menu buttons.
- Escape-to-quit keyboard handling.

Button clicks currently write to the log. Gameplay and settings screens are not implemented yet.

## Build

Requirements: CMake **3.20 or newer**, a C compiler, and SDL3 source code.

The [CMake configuration](CMakeLists.txt) expects an `SDL3/` source directory at the repository root. SDL3 is not included in this checkout. One way to provide it is:

```sh
git clone https://github.com/libsdl-org/SDL.git SDL3
cmake -S . -B build
cmake --build build
```

The SDL3 revision is not pinned by this repository. SDL's platform-specific build dependencies must also be available.

CMake copies `assets/` beside the executable after building. Run `projectzvum` from its output directory so the relative asset paths resolve. With a single-configuration generator:

```sh
cd build
./projectzvum
```

With Visual Studio, the executable is normally under `build/Debug/` or `build/Release/`.

## Source layout

- [src/main.c](src/main.c) — application lifecycle and rendering.
- [src/mainmenu.c](src/mainmenu.c) — menu textures and placement.
- [src/putman.c](src/putman.c) — keyboard and mouse input.
- `assets/` — menu button bitmaps.
