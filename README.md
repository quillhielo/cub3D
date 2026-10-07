*This project has been created as part of the 42 curriculum by @acarbajo and @albegar2.*

# cub3D

## Description

**cub3D** is a graphics project inspired by *Wolfenstein 3D*, the game considered the
first First-Person Shooter in history. The goal is to build a simple 3D game engine
from scratch, using **ray-casting** techniques and the **MiniLibX** graphics library.

The program reads a scene description file (`.cub`), parses the map and its
configuration (wall textures, floor color, ceiling color, player position), and
renders a real-time, first-person 3D view of the maze. The player can move and look
around using the keyboard.

Main features of the mandatory part:
- Parsing and validation of `.cub` scene files (map + textures + colors).
- Real-time 3D rendering of the maze using ray-casting.
- Different textures depending on the wall orientation (North, South, East, West).
- Configurable floor and ceiling colors.
- Smooth player movement (`W`, `A`, `S`, `D`) and camera rotation (arrow keys).
- Clean exit on `ESC` or when closing the window.

## Instructions

### Requirements
- A Unix-like system (Linux / macOS).
- `cc` compiler and `make`.
- MiniLibX (system version or bundled sources).

### Compilation
```bash
make        # compiles the mandatory part
make clean  # removes object files
make fclean # removes object files and the executable
make re     # fclean + make
```

### Execution
```bash
./cub3D path/to/map.cub
```

### Controls
| Key            | Action                        |
|----------------|--------------------------------|
| `W` `A` `S` `D`| Move through the maze          |
| `←` `→`        | Look left / right              |
| `ESC`          | Close the window and quit      |
| Window close (X)| Quit cleanly                  |

### Scene file (`.cub`) format
A scene file must define, in any order (except the map, which must come last):
- `NO`, `SO`, `WE`, `EA`: paths to the wall textures (North, South, West, East).
- `F`: floor color, as `R,G,B` (0-255 each).
- `C`: ceiling color, as `R,G,B` (0-255 each).
- The map itself, made only of `0` (empty space), `1` (wall) and `N`/`S`/`E`/`W`
  (player starting position and orientation). The map must be closed by walls.

Example:
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

## Resources

- [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html) — the classic reference for implementing a DDA-based ray-casting engine.
- [MiniLibX documentation](https://github.com/42Paris/minilibx-linux) — official MiniLibX sources and usage notes.
- [Raycasting in C | 42 Cub3D] (https://www.youtube.com/watch?v=G9i78WoBBIU&t=116s)
- [Cub3d approach] (https://42-fran-byte-f94097.gitlab.io/docs/cub3d/cub3d-approach-es/#/)
- [Permadi's Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) — in-depth explanation of the math behind ray-casting.

### AI usage
AI was used to help design the initial project structure and to clarify
concepts around ray-casting math (DDA algorithm, wall-distance correction to avoid
fish-eye effect) during the planning phase. All code was tested and fully
understood by the authors; no AI-generated function was copy-pasted without review.