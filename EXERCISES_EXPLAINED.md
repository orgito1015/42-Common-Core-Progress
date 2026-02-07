# 42 Programming Fundamentals Exam - Every Exercise Explained

This comprehensive guide explains **every exercise** from all 4 levels of the 42 Programming Fundamentals Exam. Each explanation includes the problem statement, approach, logic breakdown, and implementation details.

---

## Table of Contents

- [Level 1 Exercises](#level-1-exercises) (8 exercises - ⭐ Basic)
- [Level 2 Exercises](#level-2-exercises) (6 exercises - ⭐⭐ Intermediate)
- [Level 3 Exercises](#level-3-exercises) (2 exercises - ⭐⭐⭐ Advanced)
- [Level 4 Exercises](#level-4-exercises) (5 exercises - ⭐⭐⭐⭐ Complex)

---

# Level 1 Exercises

Level 1 focuses on fundamental string manipulation, basic I/O operations, and simple character transformations.

## 1. first_word

**Difficulty**: ⭐  
**File**: `first_word.c`

### Problem
Write a program that takes a string and displays its first word followed by a newline. A word is a section of string delimited by spaces/tabs or the start/end of the string. If the number of parameters is not 1, or if there are no words, display a newline.

### Approach
1. Check if there is exactly one argument
2. Skip leading whitespace (spaces and tabs)
3. Print characters until the next whitespace or end of string
4. Always print a newline at the end

### Logic Breakdown
```
Input: "  hello world"
Step 1: Skip spaces at positions 0, 1 (i becomes 2)
Step 2: Print 'h', 'e', 'l', 'l', 'o' (until space is found)
Step 3: Print newline
Output: "hello\n"
```

### Key Concepts
- **Whitespace detection**: Characters with ASCII value ≤ 32 (space and below)
- **String traversal**: Using index to iterate through string
- **Conditional output**: Only process if exactly 2 arguments (program name + string)

---

## 2. ft_putstr

**Difficulty**: ⭐  
**File**: `ft_putstr.c`

### Problem
Write a function that displays a string on standard output.

**Prototype**: `void ft_putstr(char *str);`

### Approach
1. Count the length of the string
2. Use `write()` to output the entire string at once

### Logic Breakdown
```
Input string: "Hello"
Step 1: Count length → i = 5
Step 2: write(1, "Hello", 5) → outputs entire string
```

### Key Concepts
- **Efficient I/O**: Writing the entire string in one `write()` call instead of character by character
- **String length calculation**: Incrementing counter until null terminator
- **System call**: Using `write(1, str, length)` for standard output

### Alternative Approach
Could also write character by character in a loop, but this is less efficient:
```c
while (str[i])
    write(1, &str[i++], 1);
```

---

## 3. ft_strcpy

**Difficulty**: ⭐  
**File**: `ft_strcpy.c`

### Problem
Reproduce the behavior of the `strcpy` function. Copy string `s2` into string `s1` and return `s1`.

**Prototype**: `char *ft_strcpy(char *s1, char *s2);`

### Approach
1. Iterate through source string (s2)
2. Copy each character to destination (s1)
3. Add null terminator at the end
4. Return the destination pointer

### Logic Breakdown
```
Source (s2): "Hello"
Destination (s1): [enough space allocated]

i=0: s1[0] = 'H'
i=1: s1[1] = 'e'
i=2: s1[2] = 'l'
i=3: s1[3] = 'l'
i=4: s1[4] = 'o'
i=5: s1[5] = '\0' (null terminator)

Result: s1 = "Hello"
```

### Key Concepts
- **Pointer return**: Returns destination pointer for function chaining
- **Null termination**: Essential for proper string ending
- **Assumption**: Destination has enough space (no overflow checking)

---

## 4. ft_swap

**Difficulty**: ⭐  
**File**: `ft_swap.c`

### Problem
Write a function that swaps the contents of two integers using their addresses.

**Prototype**: `void ft_swap(int *a, int *b);`

### Approach
1. Use a temporary variable to store one value
2. Assign second value to first location
3. Assign temporary value to second location

### Logic Breakdown
```
Before: a = 5, b = 10

Step 1: x = *a      → x = 5
Step 2: *a = *b     → a = 10
Step 3: *b = x      → b = 5

After: a = 10, b = 5
```

### Key Concepts
- **Pointer dereferencing**: Using `*` to access value at address
- **Temporary variable**: Required to prevent data loss during swap
- **Pass by reference**: Modifying original variables via pointers

---

## 5. rot_13

**Difficulty**: ⭐  
**File**: `rot_13.c`

### Problem
Write a program that takes a string and displays it with each alphabetical character replaced by the character 13 positions ahead in the alphabet. 'z' becomes 'm', 'Z' becomes 'M'. Non-alphabetical characters remain unchanged.

### Approach
1. Iterate through each character
2. If lowercase letter (a-m), add 13
3. If lowercase letter (n-z), subtract 13
4. Same logic for uppercase letters
5. Leave non-alphabetical characters unchanged

### Logic Breakdown
```
ROT13 cipher shifts each letter by 13 positions:

a → n, b → o, c → p ... m → z
n → a, o → b, p → c ... z → m

Example: "Hello"
H → U (uppercase)
e → r (lowercase)
l → y (lowercase)
l → y (lowercase)
o → b (lowercase)

Output: "Uryyb"
```

### Key Concepts
- **Caesar cipher**: ROT13 is a special case (shift of 13)
- **Symmetric encryption**: Applying ROT13 twice returns original text
- **ASCII manipulation**: Adding/subtracting to shift characters
- **Character range checking**: Separate handling for a-m vs n-z

---

## 6. rotone

**Difficulty**: ⭐  
**File**: `rotone.c`

### Problem
Write a program that takes a string and displays it with each alphabetical character replaced by the next one. 'z' becomes 'a', 'Z' becomes 'A'. Non-alphabetical characters remain unchanged.

### Approach
1. Handle special cases: 'z' → 'a', 'Z' → 'A'
2. For other letters, increment by 1
3. Leave non-alphabetical characters unchanged

### Logic Breakdown
```
Example: "abc"
a → b (increment)
b → c (increment)
c → d (increment)

Example: "xyz"
x → y (increment)
y → z (increment)
z → a (wrap around)

Output: "abc" → "bcd"
Output: "xyz" → "yza"
```

### Key Concepts
- **Wrap-around logic**: Special handling for end of alphabet
- **Case preservation**: Uppercase stays uppercase, lowercase stays lowercase
- **Single character shift**: ROT1 cipher (compared to ROT13)

---

## 7. search_and_replace

**Difficulty**: ⭐  
**File**: `search_and_replace.c`

### Problem
Write a program that takes 3 arguments: a string, a character to find, and a character to replace it with. Replace every occurrence of the second character with the third in the string. If arguments are invalid, display newline.

### Approach
1. Verify exactly 4 arguments (program + 3 parameters)
2. Verify second and third arguments are single characters
3. Traverse the string and replace matching characters
4. Display modified string

### Logic Breakdown
```
Input: "./search_and_replace" "hello world" "l" "X"

Validation:
- ac == 4 ✓
- av[2][1] == '\0' ✓ (single char)
- av[3][1] == '\0' ✓ (single char)

Processing "hello world":
h → h (no match)
e → e (no match)
l → X (match!)
l → X (match!)
o → o (no match)
(space) → (space)
w → w (no match)
o → o (no match)
r → r (no match)
l → X (match!)
d → d (no match)

Output: "heXXo worXd"
```

### Key Concepts
- **Argument validation**: Checking for single-character strings
- **In-place modification**: Changing characters as we iterate
- **Conditional replacement**: Only modify on match

---

## 8. ulstr

**Difficulty**: ⭐  
**File**: `ulstr.c`

### Problem
Write a program that takes a string and reverses the case of all its letters. Lowercase becomes uppercase and vice versa. Other characters remain unchanged.

### Approach
1. Check for exactly one argument
2. For each character:
   - If lowercase (a-z), convert to uppercase by subtracting 32
   - If uppercase (A-Z), convert to lowercase by adding 32
   - Otherwise, leave unchanged
3. Display the result

### Logic Breakdown
```
ASCII values:
'A' = 65, 'a' = 97
Difference = 32

Example: "HeLLo WoRLd"
H → h (uppercase, add 32)
e → E (lowercase, subtract 32)
L → l (uppercase, add 32)
L → l (uppercase, add 32)
o → O (lowercase, subtract 32)
(space) → (space) (unchanged)
W → w (uppercase, add 32)
o → O (lowercase, subtract 32)
R → r (uppercase, add 32)
L → l (uppercase, add 32)
d → D (lowercase, subtract 32)

Output: "hEllO wOrlD"
```

### Key Concepts
- **ASCII case conversion**: Difference of 32 between upper and lowercase
- **Case toggling**: Opposite transformation for each case
- **Character classification**: Checking character ranges

---

# Level 2 Exercises

Level 2 introduces more complex string operations, comparisons, and set theory concepts.

## 9. ft_atoi

**Difficulty**: ⭐⭐  
**File**: `atoi.c`

### Problem
Write a function that converts a string to an integer, handling whitespace and optional +/- signs.

**Prototype**: `int ft_atoi(const char *str);`

### Approach
1. Skip leading whitespace (spaces, tabs, newlines)
2. Handle optional sign (+ or -)
3. Convert digit characters to integer value
4. Stop at first non-digit character

### Logic Breakdown
```
Input: "   -42abc"

Step 1: Skip whitespace → i = 3
Step 2: Detect sign '-' → sign = -1, i = 4
Step 3: Process digits:
  - '4': res = 0 * 10 + 4 = 4
  - '2': res = 4 * 10 + 2 = 42
  - 'a': stop (non-digit)
Step 4: Apply sign → -1 * 42 = -42

Output: -42
```

### Key Concepts
- **Whitespace handling**: Checking for spaces and control characters (\\t, \\n, \\r)
- **Sign detection**: Single +/- at start affects final result
- **Digit conversion**: ASCII '0'-'9' converted via `(char - '0')`
- **Accumulation**: Building number with `result * 10 + digit`

### Edge Cases
- Leading zeros: "00042" → 42
- No digits: "abc" → 0
- Overflow: Not handled (standard atoi behavior)

---

## 10. ft_strcmp

**Difficulty**: ⭐⭐  
**File**: `ft_strcmp.c`

### Problem
Reproduce the behavior of the `strcmp` function. Compare two strings lexicographically.

**Prototype**: `int ft_strcmp(char *s1, char *s2);`

### Approach
1. Compare characters at same position while both strings have characters
2. Continue while characters match
3. Return difference of first non-matching characters (or difference at null terminator)

### Logic Breakdown
```
Example 1: s1 = "hello", s2 = "hello"
All characters match → return 0

Example 2: s1 = "hello", s2 = "help"
h=h, e=e, l=l, l≠p
return 'l' - 'p' = 108 - 112 = -4 (negative)

Example 3: s1 = "hello", s2 = "hel"
h=h, e=e, l=l, l≠'\0'
return 'l' - '\0' = 108 (positive)
```

### Key Concepts
- **Lexicographic comparison**: Dictionary-style ordering
- **Return value meaning**:
  - 0: strings are equal
  - < 0: s1 comes before s2
  - \> 0: s1 comes after s2
- **Null terminator handling**: Shorter string is "less than" longer string

---

## 11. ft_strrev

**Difficulty**: ⭐⭐  
**File**: `ft_strrev.c`

### Problem
Write a function that reverses a string in place.

**Prototype**: `char *ft_strrev(char *str);`

### Approach
1. Find the length of the string
2. Use two pointers: one at start, one at end
3. Swap characters and move pointers toward center
4. Stop when pointers meet

### Logic Breakdown
```
Input: "Hello"
Positions: [0]='H', [1]='e', [2]='l', [3]='l', [4]='o'

Initial: start=0, end=4
Swap 1: H ↔ o → "oellH", start=1, end=3
Swap 2: e ↔ l → "olleH", start=2, end=2
Stop (start >= end)

Output: "olleH"
```

### Key Concepts
- **In-place modification**: No additional memory allocation
- **Two-pointer technique**: Moving from both ends toward center
- **Swap algorithm**: Using temporary variable
- **Null safety**: Returns NULL for NULL input

---

## 12. inter

**Difficulty**: ⭐⭐  
**File**: `inter.c`

### Problem
Write a program that displays characters that appear in both strings, without duplicates, in the order they appear in the first string.

### Approach
1. Use an array to track which characters we've already printed
2. For each character in first string:
   - Check if it exists in second string
   - If yes and not already printed, print it and mark as seen
3. Always end with newline

### Logic Breakdown
```
Input: "./inter" "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj"

Process first string "padinton":
p: found in string 2? YES, printed? NO → print 'p', mark seen
a: found in string 2? YES, printed? NO → print 'a', mark seen
d: found in string 2? YES, printed? NO → print 'd', mark seen
i: found in string 2? YES, printed? NO → print 'i', mark seen
n: found in string 2? YES, printed? NO → print 'n', mark seen
t: found in string 2? YES, printed? NO → print 't', mark seen
o: found in string 2? YES, printed? NO → print 'o', mark seen
n: found in string 2? YES, printed? YES → skip

Output: "padinton"
```

### Key Concepts
- **Set intersection**: Finding common elements between two sets
- **Duplicate prevention**: Using seen[] array (256 elements for all ASCII)
- **Order preservation**: Following first string's character order
- **Nested loops**: Checking each character of first string against entire second string

---

## 13. union

**Difficulty**: ⭐⭐  
**File**: `union.c`

### Problem
Write a program that displays characters that appear in either string, without duplicates, in order of appearance.

### Approach
1. Use seen array to track printed characters
2. Print unique characters from first string
3. Print unique characters from second string (that weren't in first)
4. End with newline

### Logic Breakdown
```
Input: "./union" "zpadinton" "paqefwtdjetyiytjneytjoeyjnejeyj"

Process first string "zpadinton":
z → not seen, print 'z'
p → not seen, print 'p'
a → not seen, print 'a'
d → not seen, print 'd'
i → not seen, print 'i'
n → not seen, print 'n'
t → not seen, print 't'
o → not seen, print 'o'
n → already seen, skip

Process second string "paqef...":
p → already seen, skip
a → already seen, skip
q → not seen, print 'q'
e → not seen, print 'e'
f → not seen, print 'f'
w → not seen, print 'w'
... and so on

Output: "zpadintoqefwjy"
```

### Key Concepts
- **Set union**: Combining elements from both sets
- **Order matters**: First string's order, then second string's new characters
- **Duplicate elimination**: Using seen[] array across both strings
- **Sequential processing**: Two separate loops for each string

---

## 14. wdmatch

**Difficulty**: ⭐⭐  
**File**: `wdmatch.c`

### Problem
Write a program that checks if all characters of the first string appear in the second string in the same order (not necessarily consecutive).

### Approach
1. Use two pointers: one for each string
2. When characters match, advance first string pointer
3. Always advance second string pointer
4. If first pointer reaches end of string, all characters were found

### Logic Breakdown
```
Example 1: s1 = "faya", s2 = "fgvvfdxcacpolhyghbreda"

i=0, j=0: f=f ✓ → i=1
i=1, j=1: a≠g → j=2
i=1, j=2: a≠v → j=3
i=1, j=3: a≠v → j=4
i=1, j=4: a≠f → j=5
i=1, j=5: a≠d → j=6
i=1, j=6: a≠x → j=7
i=1, j=7: a≠c → j=8
i=1, j=8: a=a ✓ → i=2
... continue ...
i=3, j=18: a=a ✓ → i=4

i=4 (reached end) → s1[4] = '\0'
Output: "faya" (print the word)

Example 2: s1 = "faya", s2 = "fgvvfdxcacpolhyghbred"
Character 'a' not found again → won't print
```

### Key Concepts
- **Subsequence checking**: First string is subsequence of second
- **Greedy matching**: Take first available match
- **Two-pointer technique**: Independent traversal of both strings
- **Complete match verification**: Only print if all characters found

---

# Level 3 Exercises

Level 3 introduces dynamic memory allocation and linked list operations.

## 15. ft_range

**Difficulty**: ⭐⭐⭐  
**File**: `ft_range.c`

### Problem
Write a function that returns an array of integers containing all values from `start` to `end` (inclusive).

**Prototype**: `int *ft_range(int start, int end);`

### Approach
1. Calculate the length needed (considering direction)
2. Allocate memory for the array
3. Fill array by incrementing or decrementing based on direction
4. Return the allocated array

### Logic Breakdown
```
Example 1: start = 1, end = 3
Length = (3 - 1) + 1 = 3
Array: [1, 2, 3]

Example 2: start = 0, end = -3
Length = (0 - (-3)) + 1 = 4
Array: [0, -1, -2, -3]

Example 3: start = 5, end = 5
Length = (5 - 5) + 1 = 1
Array: [5]
```

### Key Concepts
- **Dynamic allocation**: Using `malloc()` for runtime-sized array
- **Length calculation**: Absolute value + 1 for inclusive range
- **Bidirectional filling**: Handles both ascending and descending ranges
- **Memory management**: Caller responsible for freeing returned array

### Formula Details
```c
len = (end - start) < 0 ? ((end - start) * -1) + 1 : (end - start) + 1;
```
This calculates: `abs(end - start) + 1`

---

## 16. ft_list_size

**Difficulty**: ⭐⭐⭐  
**File**: `ft_list_size.c`

### Problem
Write a function that returns the number of elements in a linked list.

**Prototype**: `int ft_list_size(t_list *begin_list);`

### Approach
1. Initialize counter to 0
2. Traverse list using a pointer
3. Increment counter for each node
4. Return final count

### Logic Breakdown
```
Linked list structure:
typedef struct s_list {
    struct s_list *next;
    void *data;
} t_list;

Example: [A] → [B] → [C] → NULL

Step 1: elem = [A], i = 0
Step 2: elem = [B], i = 1
Step 3: elem = [C], i = 2
Step 4: elem = NULL, i = 3
Return: 3
```

### Key Concepts
- **List traversal**: Following `next` pointers until NULL
- **Counter pattern**: Incrementing for each node
- **Null safety**: Empty list (NULL) returns 0
- **Pointer iteration**: Moving through nodes without modifying list

---

# Level 4 Exercises

Level 4 presents the most complex challenges involving conversions, string splitting, and advanced list operations.

## 17. ft_itoa

**Difficulty**: ⭐⭐⭐⭐  
**File**: `ft_itoa.c`

### Problem
Write a function that converts an integer to a string.

**Prototype**: `char *ft_itoa(int nbr);`

### Approach
1. Calculate required string length (including sign)
2. Allocate memory for string
3. Handle negative numbers by storing sign and working with absolute value
4. Convert digits from right to left
5. Return allocated string

### Logic Breakdown
```
Example: nbr = -1234

Step 1: Calculate length
  -1234 has 4 digits + 1 sign = 5 characters (+ null)

Step 2: Allocate 6 bytes (5 + '\0')

Step 3: Handle negative
  str[0] = '-'
  num = 1234 (absolute value)

Step 4: Fill from right to left
  i = 4: str[4] = (1234 % 10) + '0' = '4', num = 123
  i = 3: str[3] = (123 % 10) + '0' = '3', num = 12
  i = 2: str[2] = (12 % 10) + '0' = '2', num = 1
  i = 1: str[1] = (1 % 10) + '0' = '1', num = 0

Result: str = "-1234"
```

### Key Concepts
- **Length pre-calculation**: Counting digits before allocation
- **Modulo arithmetic**: Extracting rightmost digit with `% 10`
- **Integer division**: Removing rightmost digit with `/ 10`
- **Sign handling**: Using long to avoid overflow with INT_MIN
- **Reverse construction**: Building string from last digit to first

### Special Cases
- Zero: Returns "0"
- INT_MIN (-2147483648): Requires long to avoid overflow when negating

---

## 18. ft_list_foreach

**Difficulty**: ⭐⭐⭐⭐  
**File**: `ft_list_foreach.c`

### Problem
Write a function that applies a given function to each element's data in a linked list.

**Prototype**: `void ft_list_foreach(t_list *begin_list, void (*f)(void *));`

### Approach
1. Start at beginning of list
2. Apply function to current node's data
3. Move to next node
4. Repeat until end of list

### Logic Breakdown
```
List: [5] → [10] → [15] → NULL
Function: multiply_by_2(void *data)

Step 1: f([5]->data)  → 5 becomes 10
Step 2: f([10]->data) → 10 becomes 20
Step 3: f([15]->data) → 15 becomes 30

Result: [10] → [20] → [30] → NULL
```

### Key Concepts
- **Function pointers**: Passing functions as arguments
- **Generic data handling**: Using `void *` for any data type
- **List iteration**: Standard traversal pattern
- **Side effects**: Function modifies data in place

### Use Cases
- Print all elements
- Transform data (multiply, convert, etc.)
- Validate data
- Count matching elements

---

## 19. ft_list_remove_if

**Difficulty**: ⭐⭐⭐⭐  
**File**: `ft_list_remove.c`

### Problem
Write a function that removes and frees elements from a list when their data matches a reference, using a comparison function.

**Prototype**: `void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());`

### Approach
1. Handle base cases (NULL list or pointer)
2. If current node matches, remove it and recursively check again
3. If current node doesn't match, recursively check next node
4. Free removed nodes

### Logic Breakdown
```
List: [5] → [10] → [5] → [15] → NULL
data_ref: 5, cmp: compare_ints

Call 1: begin_list → [5]
  - cmp(5, 5) = 0 (match!)
  - tmp = [5], begin_list = [10]
  - free(tmp)
  - Recursive call with [10]

Call 2: begin_list → [10]
  - cmp(10, 5) ≠ 0 (no match)
  - Recursive call with next ([5])

Call 3: begin_list → [5]
  - cmp(5, 5) = 0 (match!)
  - tmp = [5], begin_list = [15]
  - free(tmp)
  - Recursive call with [15]

Call 4: begin_list → [15]
  - cmp(15, 5) ≠ 0 (no match)
  - Recursive call with next (NULL)

Result: [10] → [15] → NULL
```

### Key Concepts
- **Recursion**: Function calls itself to handle list traversal
- **Double pointer**: `t_list **` allows modifying the list pointer itself
- **Memory management**: Freeing removed nodes to prevent leaks
- **Comparison function**: Generic matching using function pointer
- **Consecutive removal**: Recursion handles multiple matches in a row

### Why Recursion?
- After removing a node, we need to check the new current node again
- Recursive approach naturally handles consecutive removals
- Cleaner than iterative approach with complex pointer manipulation

---

## 20. ft_split

**Difficulty**: ⭐⭐⭐⭐  
**File**: `ft_split.c`

### Problem
Write a function that splits a string into an array of words, where words are separated by whitespace characters (spaces, tabs, newlines).

**Prototype**: `char **ft_split(const char *str);`

### Approach
1. Count total number of words
2. Allocate array of string pointers
3. For each word:
   - Calculate word length
   - Allocate memory for word
   - Copy characters
4. Null-terminate the array

### Logic Breakdown
```
Input: "  Hello  world\t42  "

Step 1: Count words
  Skip "  " → find "Hello" (word 1)
  Skip " " → find "world" (word 2)
  Skip "\t" → find "42" (word 3)
  Total: 3 words

Step 2: Allocate array
  result = malloc(4 * sizeof(char*))  // 3 words + NULL

Step 3: Process each word

  Word 1: "Hello"
  - start = 2, end = 7, w_size = 5
  - Allocate 6 bytes (5 + '\0')
  - Copy: 'H', 'e', 'l', 'l', 'o', '\0'

  Word 2: "world"
  - start = 9, end = 14, w_size = 5
  - Allocate 6 bytes
  - Copy: 'w', 'o', 'r', 'l', 'd', '\0'

  Word 3: "42"
  - start = 15, end = 17, w_size = 2
  - Allocate 3 bytes
  - Copy: '4', '2', '\0'

Step 4: Null-terminate
  result[3] = NULL

Result: ["Hello", "world", "42", NULL]
```

### Key Concepts
- **Two-phase allocation**: First for array, then for each string
- **Delimiter detection**: Checking for spaces, tabs, newlines
- **Dynamic sizing**: Each word gets exactly needed memory
- **NULL termination**: Both strings and array end with NULL
- **Error handling**: Returns NULL on allocation failure

### Helper Function
```c
int isDelim(int c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}
```
Checks for:
- 32: space
- 9: tab (\\t)
- 10: newline (\\n)
- 11: vertical tab (\\v)
- 12: form feed (\\f)
- 13: carriage return (\\r)

---

## 21. sort_list

**Difficulty**: ⭐⭐⭐⭐  
**File**: `sort_list.c`

### Problem
Write a function that sorts a linked list using a comparison function. The function must return a pointer to the first element of the sorted list.

**Prototype**: `t_list *sort_list(t_list *lst, int (*cmp)(int, int));`

### Approach
1. Store head of list (for return value)
2. Use bubble sort: compare adjacent elements
3. When comparison returns 0, swap the data
4. After swap, restart from beginning
5. Continue until no swaps needed

### Logic Breakdown
```
List: [5] → [2] → [8] → [1] → NULL
Comparison: ascending (returns 0 if first > second)

Pass 1:
  Compare 5 and 2: cmp(5,2)=0 → swap → [2,5,8,1], restart
  Compare 2 and 5: cmp(2,5)≠0 → continue
  Compare 5 and 8: cmp(5,8)≠0 → continue
  Compare 8 and 1: cmp(8,1)=0 → swap → [2,5,1,8], restart
  Compare 2 and 5: cmp(2,5)≠0 → continue
  Compare 5 and 1: cmp(5,1)=0 → swap → [2,1,5,8], restart
  Compare 2 and 1: cmp(2,1)=0 → swap → [1,2,5,8], restart
  Compare 1 and 2: cmp(1,2)≠0 → continue
  Compare 2 and 5: cmp(2,5)≠0 → continue
  Compare 5 and 8: cmp(5,8)≠0 → continue
  Reached end → done

Result: [1] → [2] → [5] → [8] → NULL
```

### Key Concepts
- **Bubble sort algorithm**: Simple but effective for linked lists
- **In-place sorting**: Only swaps data, not node pointers
- **Comparison function**: Flexible sorting criteria
  - Return 0 to trigger swap
  - Allows ascending, descending, or custom order
- **Restart strategy**: After swap, go back to head for next pass
- **Head preservation**: Keep pointer to first node for return

### Example Comparison Functions
```c
// Ascending order
int ascending(int a, int b)
{
    return (a <= b);  // Return 0 if a > b (needs swap)
}

// Descending order
int descending(int a, int b)
{
    return (a >= b);  // Return 0 if a < b (needs swap)
}
```

### Time Complexity
- **Worst case**: O(n²) - typical for bubble sort
- **Best case**: O(n) - if list is already sorted
- **Not optimal** for large lists, but simple and works well for exam

---

## Summary of All Exercises

| Level | Exercise | Difficulty | Key Concept |
|-------|----------|------------|-------------|
| 1 | first_word | ⭐ | String parsing, whitespace handling |
| 1 | ft_putstr | ⭐ | String output, write syscall |
| 1 | ft_strcpy | ⭐ | String copying, pointers |
| 1 | ft_swap | ⭐ | Pointer manipulation, swapping |
| 1 | rot_13 | ⭐ | Caesar cipher, character rotation |
| 1 | rotone | ⭐ | Character shifting, wrap-around |
| 1 | search_and_replace | ⭐ | String search, replacement |
| 1 | ulstr | ⭐ | Case conversion, ASCII manipulation |
| 2 | ft_atoi | ⭐⭐ | String to integer conversion |
| 2 | ft_strcmp | ⭐⭐ | String comparison, lexicographic order |
| 2 | ft_strrev | ⭐⭐ | In-place string reversal |
| 2 | inter | ⭐⭐ | Set intersection, duplicate prevention |
| 2 | union | ⭐⭐ | Set union, character tracking |
| 2 | wdmatch | ⭐⭐ | Subsequence matching, two pointers |
| 3 | ft_range | ⭐⭐⭐ | Dynamic allocation, array generation |
| 3 | ft_list_size | ⭐⭐⭐ | Linked list traversal, counting |
| 4 | ft_itoa | ⭐⭐⭐⭐ | Integer to string conversion |
| 4 | ft_list_foreach | ⭐⭐⭐⭐ | Function pointers, list iteration |
| 4 | ft_list_remove_if | ⭐⭐⭐⭐ | Recursive list manipulation, memory management |
| 4 | ft_split | ⭐⭐⭐⭐ | String parsing, 2D allocation |
| 4 | sort_list | ⭐⭐⭐⭐ | Linked list sorting, bubble sort |

---

## General Exam Tips

### Time Management
1. **Start with Level 1**: Build confidence with easier problems
2. **Read carefully**: Understand requirements before coding
3. **Test as you go**: Verify each function works before moving on
4. **Save complex for last**: Level 4 exercises take the most time

### Common Pitfalls
- **Forgetting null terminators**: Always add '\\0' to strings
- **Memory leaks**: Free all allocated memory
- **Off-by-one errors**: Careful with loop boundaries
- **Null pointer checks**: Verify pointers before dereferencing

### Testing Strategy
```bash
# Compile with strict flags
gcc -Wall -Wextra -Werror your_file.c

# Test edge cases
./program ""           # Empty string
./program "   "        # Only whitespace
./program "a"          # Single character
./program              # No arguments
```

### Debugging Techniques
1. **Print intermediate values**: Use printf to trace execution
2. **Check return values**: Verify malloc doesn't return NULL
3. **Validate input**: Ensure arguments are valid before processing
4. **Test incrementally**: Build and test function step by step

---

## Conclusion

This guide has explained every exercise from all 4 levels of the 42 Programming Fundamentals Exam. Each exercise builds upon concepts from previous levels:

- **Level 1** establishes basic string manipulation and I/O
- **Level 2** introduces algorithms and set operations
- **Level 3** adds memory management and data structures
- **Level 4** combines all concepts for complex challenges

Remember: Understanding the logic is more important than memorizing code. Practice implementing these solutions from scratch to build true mastery.

**Good luck with your exam! 🚀**

---

*Last updated: February 2026*  
*Repository: [orgito1015/42-Common-Core-Progress](https://github.com/orgito1015/42-Common-Core-Progress)*
