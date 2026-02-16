*This project has been created as part of the 42 curriculum by ajeffers.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using only two stacks (`a` and `b`) and a limited set of operations, while minimizing the total number of operations used.

The available operations are:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top element of `b` onto `a` |
| `pb` | Push the top element of `a` onto `b` |
| `ra` | Rotate stack `a` upward (first element becomes last) |
| `rb` | Rotate stack `b` upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack `a` (last element becomes first) |
| `rrb` | Reverse rotate stack `b` |
| `rrr` | `rra` and `rrb` simultaneously |

### Algorithm: Turkish Sort

This implementation uses the **Turkish algorithm** (also known as the "mechanical turk" or cost-based approach). It works as follows:

1. **Push all but 3 elements** from stack `a` to stack `b`. For each node in `a`, the algorithm calculates the cheapest node to push based on the combined rotation cost for both stacks.
2. **Target assignment**: Each node in `a` is assigned a target in `b` — the closest smaller value. If no smaller value exists, the target becomes `b`'s maximum.
3. **Cost analysis**: The push cost of each node is the sum of rotations needed to bring both the node and its target to the top of their respective stacks. Nodes above the median use `ra`/`rb`; nodes below use `rra`/`rrb`. When both are on the same side, combined rotations (`rr`/`rrr`) are used to save operations.
4. **Sort three**: Once only 3 elements remain in `a`, they are sorted with at most 2 operations.
5. **Push back**: All elements are pushed from `b` back to `a`. Each `b` node targets the closest larger value in `a`.
6. **Final rotation**: The minimum value is rotated to the top of `a`.

## Instructions

### Requirements

- A C compiler (`cc`, `gcc`, or `clang`)
- `make`

### Compilation

```bash
make        # Build the push_swap binary
make clean  # Remove object files
make fclean # Remove object files and the binary
make re     # Full recompile
```

### Usage

```bash
# Pass integers as separate arguments
./push_swap 4 67 3 87 23

# Pass integers as a single quoted string
./push_swap "4 67 3 87 23"
```

The program outputs the list of operations to `stdout`, one per line. If the input is already sorted, nothing is printed.

### Error Handling

The program prints `Error` to `stderr` and exits in the following cases:
- Non-numeric arguments
- Duplicate values
- Values outside the `int` range (`-2147483648` to `2147483647`)

### Verifying the Output

You can count the number of operations:

```bash
./push_swap 5 3 1 4 2 | wc -l
```

## Performance

Benchmarked over multiple runs with random inputs:

| Input Size | Average Operations | 42 Threshold (5 points) |
|------------|-------------------|------------------------|
| 3 | ≤ 2 | 3 |
| 5 | ~8–12 | 12 |
| 100 | ~560–600 | 700 |
| 500 | ~5300–5450 | 5500 |

## Project Structure

```
push_swap/
├── Makefile
├── push_swap.h          # Header — struct definition and prototypes
├── push_swap.c          # main() — argument parsing and entry point
├── init.c               # Stack initialization and input validation
├── init_nodes.c         # Target assignment, cost analysis, cheapest selection
├── sort_stack.c         # Main Turkish algorithm sorting loop
├── sort_small.c         # sort_three (3-element sort)
├── stack_utils.c        # stack_len, find_last, find_min, find_max, is_sorted
├── utils.c              # ft_atol, free helpers, get_cheapest, prep_for_push
├── swaps.c              # sa, sb, ss
├── push.c               # pa, pb
├── rotations.c          # ra, rb, rr
├── rrotations.c         # rra, rrb, rrr
├── ft_split.c           # ft_split (string splitting utility)
├── ft_strlen.c          # ft_strlen
├── ft_substr.c          # ft_substr
└── ft_strlcpy.c         # ft_strlcpy
```

## Resources

- [push_swap subject (42)](https://projects.intra.42.fr/projects/push_swap) — official project page
- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — article on the Turkish algorithm by A. Yigit Ogun
- [Visualizer for push_swap](https://github.com/o-reo/push_swap_visualizer) — useful tool for debugging and understanding stack movements
