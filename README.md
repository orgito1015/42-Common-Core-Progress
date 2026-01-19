<p align="center">
  <img src="https://github.com/user-attachments/assets/bc050aac-55b7-463a-805d-d2847f483e06" alt="42 Common Core Progress" width="900">
</p>

# 42 Common Core Progress

This repository tracks my journey through the **42 Common Core** curriculum.  
It includes complete project implementations, evaluation processes, comprehensive documentation, and full solutions for all completed projects.

---

## 📂 Projects

### Core Projects

#### 🔹 [libft-full](./libft-full)
**Status**: ✅ Completed  
Complete implementation of the foundational C library containing essential functions for memory handling, string manipulation, character checks, and linked list operations. This library serves as the foundation for all future 42 projects.

**Key Features**:
- Standard C library function reimplementations
- Memory manipulation functions
- String and character utilities
- Linked list operations (bonus part)

---

#### 🔹 [Get-Next-Line](./Get-Next-Line)
**Status**: ✅ Completed  
Implementation of a function that reads a line from a file descriptor, managing static variables and buffer handling efficiently.

**Key Features**:
- Buffer-based reading with configurable `BUFFER_SIZE`
- Static variable management for multi-call persistence
- Handles multiple file descriptors
- Memory-efficient line extraction

**Additional Resources**:
- [Get-Next-Line Evaluation Process](./Get-Next-Line%20Evaluation%20Process) — Evaluation scripts, tests, and validation tools

---

#### 🔹 [Printf](./Printf)
**Status**: ✅ Completed  
Custom implementation of the C standard library `printf` function, supporting multiple format specifiers and variadic functions.

**Supported Conversions**: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`

**Key Features**:
- Variadic function implementation
- Clean dispatcher design
- Direct output via `write(2)` (no buffering)
- Norm-compliant code structure

**Additional Resources**:
- [Printf Evaluation Process](./Printf%20Evaluation%20Process) — Testing suite and evaluation materials

---

#### 🔹 [Push_Swap Full Project](./Push_Swap%20Full%20Project)
**Status**: ✅ Completed  
Advanced sorting algorithm project that sorts integers using two stacks and a limited instruction set, with multiple optimization strategies.

**Key Features**:
- Four sorting strategies: Simple O(n²), Medium O(n√n), Complex O(n log n), and Adaptive
- Benchmark mode for performance analysis
- Disorder metric calculation
- Comprehensive error handling
- Custom doubly-linked stack implementation

**Performance Targets**:
- 100 numbers: < 700 operations (excellent)
- 500 numbers: < 5500 operations (excellent)

---

#### 🔹 [ExamProgrammingFundamentals](./ExamProgrammingFundamentals)
**Status**: ✅ Completed (18/18 exercises)  
Complete solutions for all 4 levels of the 42 Common Core Programming Fundamentals Exam.

**Structure**:
- **Level 1** (8 exercises): Basic string manipulation and I/O
- **Level 2** (5 exercises): Intermediate string operations and parsing
- **Level 3** (2 exercises): Dynamic memory allocation and linked lists
- **Level 4** (3 exercises): Advanced conversions and complex algorithms

---

## 🎯 Purpose

This repository serves multiple objectives:

- **Organization**: Keep all 42 projects structured and accessible
- **Documentation**: Maintain comprehensive notes and evaluation processes
- **Resource Sharing**: Provide working solutions and explanations for fellow students
- **Progress Tracking**: Document my journey through the 42 curriculum
- **Learning Tool**: Help others following the same educational path

---

## 🛠 Technical Stack

- **Language**: C
- **Compiler**: `gcc` with flags: `-Wall -Wextra -Werror`
- **Norm**: 42 Norminette (strict compliance)
- **Build System**: Makefiles for all projects
- **Version Control**: Git

---

## 📊 Progress Overview

| Project | Status | Complexity | Key Concepts |
|---------|--------|------------|--------------|
| libft | ✅ Complete | ⭐⭐ | Memory management, String manipulation |
| Get Next Line | ✅ Complete | ⭐⭐ | File I/O, Static variables, Buffer handling |
| ft_printf | ✅ Complete | ⭐⭐⭐ | Variadic functions, Format parsing |
| Push_Swap | ✅ Complete | ⭐⭐⭐⭐ | Sorting algorithms, Algorithm optimization |
| Exam Rank 02 | ✅ Complete | ⭐⭐⭐ | Problem solving, Time management |

---

## 🚀 Getting Started

### Prerequisites
- Unix-based operating system (Linux/macOS)
- GCC compiler
- Make
- 42 Norminette (for norm checking)

### Cloning the Repository
```bash
git clone https://github.com/orgito1015/42-Common-Core-Progress.git
cd 42-Common-Core-Progress
```

### Building Individual Projects
Each project contains its own Makefile:

```bash
# Example: Building libft
cd libft-full
make

# Example: Building ft_printf
cd Printf
make

# Example: Building push_swap
cd "Push_Swap Full Project"
make
```

---

## 📁 Repository Structure

```
42-Common-Core-Progress/
├── 42 Common Core Progress.png        # Repository banner
├── README.md                          # This file
├── libft-full/                        # Complete libft implementation
├── Get-Next-Line/                     # GNL main implementation
├── Get-Next-Line Evaluation Process/  # GNL testing and evaluation
├── Printf/                            # ft_printf implementation
├── Printf Evaluation Process/         # ft_printf testing and evaluation
├── Push_Swap Full Project/            # Push_swap with multiple strategies
└── ExamProgrammingFundamentals/       # Complete exam solutions (Levels 1-4)
```

---

## 📝 Notes

- All projects are **Norminette compliant**
- No memory leaks in any implementation
- Comprehensive error handling throughout
- Each project includes its own detailed README
- Evaluation processes and test suites are included where applicable

---

## 👤 Author

**Orgito Leka**  
42 Student  
GitHub: [@orgito1015](https://github.com/orgito1015)

---

## 🤝 Contributing

While this is a personal progress repository, feedback and suggestions are always welcome! Feel free to open an issue if you spot any problems or have questions about implementations.

---

## ⚖️ License

This repository is for educational purposes. Please respect 42's academic integrity policies when using these resources.

---

## 🙏 Acknowledgments

Special thanks to:
- The 42 Network for providing an innovative peer-to-peer learning environment
- Fellow students who contributed to exam solutions
- The 42 community for their support and collaboration

---

**Last Updated**: January 2026  
**Current Status**: Actively progressing through 42 Common Core
