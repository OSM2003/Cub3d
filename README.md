# Cub3d

A small Wolfenstein-like raycasting project (Cub3D) implemented in C. This repository contains the game source, a custom libft, map samples and a vendored MLX42 submodule used to open a window, render textures and handle input.

This README provides a minimal set of instructions to build and run the project on a Linux system.

## Prerequisites

- A POSIX-compatible OS (Linux is recommended)
- A C compiler (clang or gcc)
- make
- cmake (required by MLX42)
- X11 / appropriate graphics libraries for MLX42 (usually installed with your distribution)

On Debian/Ubuntu you can install common dependencies with:

```sh
# install build tools and X11 development libraries
sudo apt update
sudo apt install build-essential cmake libx11-dev libxext-dev libxrandr-dev libxinerama-dev libxcursor-dev libxft-dev
```

If you use macOS or another OS, adapt the dependency installation accordingly. MLX42 may require different setup on macOS.

## Build

This project uses a `Makefile`. From the repository root run:

```sh
make
```

This should build the project and (depending on the Makefile) produce an executable (for example `cub3d` or similar). If the build fails, inspect the `Makefile` and ensure MLX42 is available and compiled (some projects include MLX42 in `MLX42/` and provide a target to build it).

Common make targets:

- `make` — default build
- `make clean` — remove object files
- `make fclean` — remove object files and binaries
- `make re` — full clean and rebuild

## Run

After a successful build, run the executable with a map file (`.cub`) from the `maps/valid/` folder. Example:

```sh
./cub3d maps/valid/subject_map.cub
```

Replace `cub3d` with the actual executable name produced by your build if different.

If the executable prints usage or error messages, follow them (missing textures, invalid map format, etc.).

## Controls

Typical controls for Cub3D-style projects (may vary by implementation):

- W / Up arrow — move forward
- S / Down arrow — move backward
- A / Left arrow — move left / strafe
- D / Right arrow — move right / strafe
- Left / Right arrows or mouse — rotate view
- ESC — exit

Check `SRC/` or `raycasting` input handling code for the exact keys used by this project.

## Maps

Map samples are included in the `maps/valid/` and `maps/not_valid/` folders. Use the valid maps to run the game and the invalid maps as test cases for the parser.

## Visuals

Below are a few example textures included in the repository and a small ASCII map example to illustrate how maps are laid out. If you open this README on GitHub or a local Markdown viewer the images will render if the paths are correct.

Textures (thumbnails):

![Brick texture](textures/brick.png)
![Glass texture](textures/glass.png)
![Leaves texture](textures/leavesop.png)

Gameplay screenshot (placeholder):

If you want to add a gameplay screenshot, place an image at `Screenshot .png` (or update the path below) and it will render here:

![Gameplay screenshot](Screenshot .png)

ASCII map example:

```txt
1111111111111111111
1001001001001001001
1001001001001001001
1001001001001001001
1001001000001001001
100000000S000000001
1000011111111000001
1111000000000001111
1000000101010000001
1111111111111111111   
```

Legend:
- `1` — wall
- `0` — empty space (floor)
- `P` — player start


## Troubleshooting

- If the build fails with missing MLX42 headers or libraries, build MLX42 first (see `MLX42/README.md` inside the `MLX42` folder if present) or install the necessary system packages.
- If the window fails to open, ensure your graphics/X11 environment is running and the development headers are installed.
- For texture/asset load errors, confirm the `textures/` images exist and paths in map files are correct.

## License

This repository may include third-party code and libraries. Check the `LICENSE` files in the repository and inside `MLX42/` for license details.

## Contributing

Small, focused patches that fix bugs or improve documentation are welcome. Open a PR with a clear description of the change.

---

If you want, I can also:

- Detect the exact executable name produced by your `Makefile` and update the `Run` section.
- Add a short developer setup or CI instructions.

Tell me which of the above you'd like next.
