# Analysis of Algorithms (AOA) Lab Work

C++ programs written for an Analysis of Algorithms course, organised by lab and task. Many of them count comparisons or operations so you can compare how algorithms behave as the input grows. The repo also holds the lab handouts and assignment write-ups (`.pdf` / `.docx`).

## Tech stack

- C++ (standard library only)
- g++ (MinGW-w64 / MSYS2 UCRT64) with VS Code build and debug configs in `.vscode/`

## Contents

| Lab | Files | Topics |
|-----|-------|--------|
| 1 | `Lab1task1-4.cpp` | Linear vs. binary search comparison counts; operation counting for nested loops |
| 2 | `lab2task1-5.cpp` | Brute force: linear search, pattern matching, password cracking, string permutations with bubble sort, character frequency |
| 3 | `lab3task1-2.cpp` | Merge sort (parcels); quick sort on patient records |
| 4 | `lab4task1-2.cpp` | Maximal points: brute force vs. plane sweep (with merge sort) |
| 5 | `lab5task1-3.cpp` | Fibonacci, climbing stairs, knapsack |
| 6 | `lab6task1-3.cpp` | Coin change, activity selection, 0/1 knapsack (DP table) |
| 7 | `lab7task1-2.cpp` | Brute-force PIN search; appointment schedule optimisation |
| 9 | `lab9task1-7.cpp` | Binary trees / BST: traversals, node counts, height, search, min/max, deletion |
| 10 | `lab10task1-4.cpp` | Graphs: adjacency matrix and adjacency list, edge checks and edge counting |
| 12 | `lab12task1-5.cpp` | Character frequency and Huffman coding |

`lab3.cpp`, `prc.cpp` and `prct.cpp` are unfinished practice drafts and do not compile as they are.

## Project structure

```
*.cpp        lab task source files (one program per file)
*.exe        compiled binaries committed earlier (Windows)
*.pdf/.docx  lab handouts and assignment reports
.vscode/     g++ build task and debugger settings
```

## Building and running

Each `.cpp` file is a standalone program with its own `main()`. Compile and run one at a time:

```bash
g++ -std=c++17 lab9task2.cpp -o lab9task2
./lab9task2
```

In VS Code, open a `.cpp` file and run the default build task (**C/C++: g++.exe build active file**). It uses the g++ path set in `.vscode/tasks.json` (`C:\msys64\ucrt64\bin\g++.exe`), so change that path if your compiler is installed somewhere else.
