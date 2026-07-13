# AlgVis

AlgVis is a small command-line C project for visualizing common algorithms and data structures. It is designed as an interactive learning tool, with simple console output that shows how each algorithm works step by step.

## Features

The program currently includes demos for:

- Binary Search
- Linear Search
- Insertion Sort
- Merge Sort
- Linked List
- Hash Map

## Requirements

To build and run the project, you need:

- A C compiler such as GCC
- Make

## Build

From the project root, run:

```bash
make
```

## Run

After building, start the program with:

```bash
./algvis
```

You will then be prompted to choose an algorithm by entering one of the supported commands:

- `bs` for Binary Search
- `ls` for Linear Search
- `is` for Insertion Sort
- `ms` for Merge Sort
- `ll` for Linked List Demo
- `hm` for Hash Map Demo

## Project Structure

- `main.c` / `main.h` — program entry point and menu
- `helperFunctions.c` / `helperFunctions.h` — shared helper functions for array generation and display
- `algs/` — algorithm and data structure demo implementations

## Notes

This project is intentionally simple and beginner-friendly. The goal is to make algorithm behavior easier to understand through clear console-based visualization.
