# 📚 Exam Programming Fundamentals

This directory contains comprehensive solutions for the **42 Common Core Programming Fundamentals Exam**. The exam is structured into **4 progressive levels**, each testing increasingly complex C programming concepts and problem-solving skills.

## 📋 Overview

The **Exam Programming Fundamentals** is a critical milestone in the 42 curriculum, designed to validate foundational programming skills under timed conditions. This repository provides solutions for all levels, demonstrating proper implementation techniques while adhering to **42 Norm** standards.

## 🎯 Exam Structure

The exam consists of **4 levels** with increasing difficulty:

### Level 1 - Basic Fundamentals
**Focus**: String manipulation, basic I/O, fundamental logic  
**Difficulty**: ⭐  
**Exercises**: 8 problems

Core concepts covered:
- String operations (copy, length, output)
- Character manipulation (case conversion, rotation)
- Basic search and replace algorithms
- Integer operations (swap)

📖 [View Level 1 README](./Level%201/README.md)

**Exercises**:
- `first_word` - Extract and print the first word from a string
- `ft_putstr` - Display a string on standard output
- `ft_strcpy` - Copy a string to another buffer
- `ft_swap` - Swap two integer values
- `rot_13` - Apply ROT13 cipher transformation
- `rotone` - Rotate characters by one position in alphabet
- `search_and_replace` - Replace character occurrences in a string
- `ulstr` - Toggle uppercase and lowercase characters

### Level 2 - Intermediate Operations
**Focus**: String comparison, parsing, set operations  
**Difficulty**: ⭐⭐  
**Exercises**: 5 problems

Core concepts covered:
- Lexicographic string comparison
- In-place string manipulation
- Set theory operations on character strings
- Pattern matching algorithms
- String to integer conversion

📖 [View Level 2 README](./Level%202%20/README.md)

**Exercises**:
- `ft_strcmp` - Compare two strings lexicographically
- `ft_strrev` - Reverse a string in place
- `inter` - Display common characters between two strings (intersection)
- `union` - Display unique characters from two strings (union)
- `wdmatch` - Verify if a word can be formed from another string

### Level 3 - Advanced Logic
**Focus**: Dynamic memory allocation, linked lists  
**Difficulty**: ⭐⭐⭐  
**Exercises**: 2 problems

Core concepts covered:
- Dynamic array creation with `malloc`
- Linked list traversal
- Range generation algorithms
- Memory management

**Exercises**:
- `ft_range` - Create an array of integers within a specified range
- `ft_list_size` - Count the number of elements in a linked list

### Level 4 - Complex Algorithms
**Focus**: Advanced conversions, list operations  
**Difficulty**: ⭐⭐⭐⭐  
**Exercises**: 3 problems

Core concepts covered:
- Integer to string conversion
- String to integer parsing
- Linked list iteration with function application
- Memory allocation for dynamic strings

**Exercises**:
- `ft_itoa` - Convert an integer to a string
- `atoi` - Convert a string to an integer
- `ft_list_foreach` - Apply a function to each element of a linked list

## 🛠️ Technical Requirements

### Compilation
```bash
gcc -Wall -Wextra -Werror <file.c>
```

### Constraints
- **Language**: C
- **Norm**: Must comply with 42 Norminette
- **Allowed functions**: Specified per exercise (typically `write`, `malloc`, etc.)
- **Forbidden functions**: Any function not explicitly allowed
- **Memory**: No memory leaks permitted
- **Files**: One implementation per exercise

### Testing Your Solutions
Each exercise can be compiled and tested individually:

```bash
# Compile
gcc -Wall -Wextra -Werror <exercise.c> -o <exercise>

# Run
./<exercise> [arguments]
```

## 📊 Progress Summary

| Level | Exercises | Completed | Difficulty |
|-------|-----------|-----------|------------|
| Level 1 | 8 | ✅ 8/8 | ⭐ |
| Level 2 | 5 | ✅ 5/5 | ⭐⭐ |
| Level 3 | 2 | ✅ 2/2 | ⭐⭐⭐ |
| Level 4 | 3 | ✅ 3/3 | ⭐⭐⭐⭐ |
| **Total** | **18** | **✅ 18/18** | - |

## 💡 Exam Tips

1. **Read carefully**: Understand the exact requirements before coding
2. **Test thoroughly**: Check edge cases (NULL, empty strings, negative numbers)
3. **Follow the norm**: Norminette compliance is mandatory
4. **Memory management**: Always free allocated memory
5. **Time management**: Start with exercises you're most comfortable with
6. **Practice**: Repetition is key to exam success

## 📁 Directory Structure

```
ExamProgrammingFundamentals/
├── README.md (this file)
├── Level 1/
│   ├── README.md
│   └── [8 exercise files]
├── Level 2 /
│   ├── README.md
│   └── [5 exercise files]
├── Level 3/
│   └── [2 exercise files + linked list implementations]
└── Level 4/
    └── [3 exercise files + linked list implementations]
```

## 🎓 Learning Outcomes

By completing these exercises, students will master:
- ✅ String manipulation and parsing
- ✅ Memory allocation and management
- ✅ Linked list operations
- ✅ Algorithm implementation
- ✅ 42 Norm compliance
- ✅ Problem-solving under time constraints

## 📚 Additional Resources

- [42 Norminette Documentation](https://github.com/42School/norminette)
- [42 Exam Guide](https://github.com/pasqualerossi/42-School-Exam-Rank-02)
- Practice with similar exercises on [Examshell](https://github.com/JCluzet/42_EXAM)

## 🙏 Credits

Special thanks to the contributors who helped develop these solutions:

- [@fabiaballa-42](https://github.com/fabiaballa-42)
- [@ArsenScorpio05](https://github.com/ArsenScorpio05)
- [@Adrianov03](https://github.com/Adrianov03)
- [@helenkace42](https://github.com/helenakace42)

---

**Note**: These solutions are provided for educational purposes. Understanding the logic behind each solution is more important than memorizing the code. Good luck with your exam! 🚀
