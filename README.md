# Bio++ (Bpp) 🧬💻
**Learning C++ Through Biology**

An introductory, project-based C++ learning repo: use familiar cell biology to understand classes, objects, namespaces, state, queues, resource management, and safety checks.

> **Note:** This is an independent educational project, **not** the existing [Bio++ bioinformatics library](https://github.com/BioPP).

## Bio → Machine
| Biology | Machine / C++ analogy |
|---|---|
| DNA | Source code / stored instructions |
| Cell membrane | Input/output boundary and validation |
| Protein packages | Messages / data packets |
| Vacuoles | Cleanup / resource release |
| Mitochondria | Energy budget / power management |
| Endoplasmic reticulum (ER) | Assembly and transport pipeline |
| Ribosomes | Translation of instructions into products (roughly a build/execution pipeline) |

These are **teaching analogies**, not literal biological or computing equivalences.

## Quick start
Requires a C++17 compiler (GCC, Clang, or MSVC).

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp -o biopp
./biopp
```

Windows PowerShell with g++:
```powershell
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp -o biopp.exe
.\biopp.exe
```

## Run tests
```bash
g++ -std=c++17 -Wall -Wextra -pedantic tests/test_cell.cpp -o test_cell
./test_cell
```

Or use CMake:
```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Learning path
1. Read `docs/01-mapping.md` for the analogies.
2. Read `docs/02-cpp-cheatsheet.md` for `namespace::Class object;`.
3. Explore `src/cell.hpp` (classes, private data, methods).
4. Run `src/main.cpp` (messages, processing, energy, cleanup).
5. Modify a threshold and predict the result before running.
6. Add a test in `tests/test_cell.cpp`.

## Project status
**Version 0.1:** Self-contained learning scaffold. Not a biologically accurate simulation.

## Next ideas
- Model gene expression more realistically (DNA → RNA → protein).
- Add cell signaling and multiple cells.
- Introduce time steps, feedback loops, and energy constraints.
- Compare cell regulation to embedded-system safety.

## Naming
Repo: `bio-plus-plus` · Project: **Bio++ (Bpp)**
