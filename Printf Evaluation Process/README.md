# Printf Evaluation Process

This folder contains a small testing environment to help you verify the behavior of your `ft_printf` implementation for the 42 Common Core project.

## 📁 Folder Structure

- `mains/` — Test files
- `Makefile` — Compiles all tests
- `README.md` — This documentation file

## 🚀 How to Use

1. Place your `ft_printf` source files inside a folder named `src/`.
2. Run:

```
make
```

3. Execute the generated test programs:

```
./test_basic
./test_numbers
./test_hex_pointer
./test_mixed
```

Each test displays:
- Output printed by **ft_printf**
- Output printed by the real **printf**
- Return values for both (so you can compare correctness)

## 🎯 Purpose of This Repo

This testing setup helps you easily validate:

- Output correctness
- Matching return values
- Proper handling of edge cases:
  - NULL strings
  - Negative numbers
  - Unsigned values
  - Hexadecimal formatting
  - Pointer formatting

It is especially useful when preparing for the **42 evaluation**.

## ℹ️ Note

This folder is **only for testing your project**.  
It is *not* meant to be submitted as part of the official `ft_printf` project.
