*This project has been created as part of the 42 curriculum by Orgito Leka, Izabela Velcani*

# push_swap

Sort a list of integers using **two stacks** (`a` and `b`) and a **limited instruction set**, while minimizing the number of operations.  
This implementation provides **four strategies** (O(n²), O(n√n), O(n log n), and an **adaptive** strategy based on a disorder metric), a **benchmark mode**, and strict **error handling**.

---

## Table of Contents
- `Features`
- `Build - Usage`
- `CLI Flags`
- `Examples`
- `Error Handling`
- `Design & Algorithms`
- `Benchmark Mode`
- `Performance Notes`
- `Project Structure`
- `Resources & How AI Was Used`

---

## Features
- Two-stack sorting with the required operations set.
- **Four strategies** in one binary:
  - **Simple (O(n²))**: selection-sort style.
  - **Medium (O(n√n))**: chunk-based partitioning.
  - **Complex (O(n log n))**: radix sort on index-compressed values.
  - **Adaptive**: chooses strategy based on disorder metric.
- **Benchmark mode (`--bench`)** reports:
  - Disorder (%), strategy name + complexity class
  - Total operations and per-operation counts
- Strict parsing & validation:
  - Accepts `./push_swap 2 1 3` or `./push_swap "2 1 3"`
  - Rejects invalid integers, out-of-range values, duplicates
- No global variables; custom doubly-linked stack implementation.

---

## Build
```bash
make            # builds push_swap with -Wall -Wextra -Werror
make clean      # removes object files
make fclean     # removes objects and binary
make re         # full rebuild
```

---

## Usage
```bash
./push_swap [--bench] [--simple|--medium|--complex|--adaptive]
```

- If no strategy flag is given, `--adaptive` is used by default.
- Operations are printed to `stdout`; benchmark output goes to `stderr`.

---

## CLI Flags
`--simple`   → force `O(n²)` strategy
`--medium`   → force `O(n√n)` strategy
`--complex`  → force `O(n log n)` strategy
`--adaptive` → default; picks strategy based on disorder
`--bench`    → prints metrics to `stderr` after sorting

## Examples

```bash

# Basic run
./push_swap 2 1 3 6 5 8

# Force strategies
./push_swap --simple 5 4 3 2 1
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23

# With benchmark
./push_swap --bench --adaptive "4 67 3 87 23" 2>bench.txt | ./checker_os && cat bench.txt
./push_swap --bench --adaptive 4 67 3 87 23 2>bench.txt | ./checker_os && cat bench.txt
```

### Extra Tests
Here are additional tests using shuf for 100 and 500 numbers for each strategy:
```bash

# Adaptive strategy
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap --bench --adaptive $(cat args.txt) 2>bench.txt | ./checker_os && cat bench.txt

shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench --adaptive $(cat args.txt) 2>bench.txt | ./checker_os && cat bench.txt

# Simple strategy
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap --bench --simple $(cat args.txt) 2>bench.txt | ./checker_os && cat bench.txt

shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench --simple $(cat args.txt) 2>bench.txt | ./checker_os && cat bench.txt

# Medium strategy
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap --bench --medium $(cat args.txt) 2>bench.txt | ./checker_os && cat bench.txt

shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench --medium $(cat args.txt) 2>bench.txt | ./checker_os && cat bench.txt

# Complex strategy
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap --bench --complex $(cat args.txt) 2>bench.txt | ./checker_os && cat bench.txt

shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench --complex $(cat args.txt) 2>bench.txt | ./checker_os && cat bench.txt
```

---

## Error Handling
- Prints `Error\n` to `stderr` and exits non-zero on invalid input.
- Rejects:
  - Non-integers, empty tokens, +/- only
  - Out-of-range values (`INT_MIN`..`INT_MAX`)
  - Duplicates

---

## Design & Algorithms
### Disorder Metric
- Computed before any moves using pair-inversion ratio.
- Internal range: 0..1; printed as percentage in --bench.

### Index Compression
- Assigns ranks to values for consistent comparisons and radix passes.

### Strategies
- `Simple (O(n²))`: selection-sort style.
- `Medium (O(n√n))`: chunk-based partitioning.
- `Complex (O(n log n))`: radix sort.
- `Adaptive`: picks strategy based on disorder thresholds.

---

## Benchmark Mode
Example output:
```yaml
[bench] disorder: 49.93%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 7997
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 4840 rb: 1098 rr: 0 rra: 0 rrb: 1059 rrr: 0
```

---

## Performance Notes
### Expected targets
```yaml
100 numbers: < 2000 ops (pass), < 1500 (good), < 700 (excellent)
500 numbers: < 12000 ops (pass), < 8000 (good), < 5500 (excellent)
```

### Project Structure
```yaml
├── push_swap.c
├── push_swap.h
├── Makefile
├── arguments_parser.c
├── arguments_parser_split.c
├── arguments_validate_input.c
├── push_swap_helpers.c
├── b_stack_core.c
├── b_core_utils.c
├── b_value_indexing.c
├── b_disorder_metrics.c
├── ops_push_and_swap.c
├── ops_rotate.c
├── ops_reverse_rotate.c
├── algorithms_simple_sorting.c
├── algorithms_sorting.c
├── algorithms_special_sort.c
├── algorithms_radix_sorting.c
├── algorithms_chunk_based_sorting.c
├── algorithms_adaptive_sort_strategy.c
├── benchmark_operations_1.c
├── benchmark_operations_2.c
├── benchmark_operations_3.c
├── benchmark_operations_4.c
├── libft_functions_1.c
└── libft_functions_2.c
```

---

## Resources & How AI Was Used
- `References`: stack-based sorting, radix sort, chunk partitioning and double linked lists through online tutorials or Wikipedia and strategy usage `medium.com` articles.
- `AI usage`: AI was used for checking purposes, especialy to make sure there were no conflicts on function callings.
