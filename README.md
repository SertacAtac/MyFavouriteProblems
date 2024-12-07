# Lexicographical Permutations

This program generates all **lexicographical permutations** of a list of strings in ascending order. It utilizes a custom implementation of the next permutation algorithm and swaps to determine the subsequent order of strings.

## Features
- Reads a list of up to `n` strings.
- Calculates and displays all lexicographical permutations of the strings.
- Efficiently swaps and reverses portions of the string list for permutation generation.

## Code Overview

### **Core Functionality**
1. **`swap(char* a, char* b)`**
   - Swaps two strings using pointers.
   - Utilized during the reordering process in the `next_permutation` function.

2. **`next_permutation(int n, char **s)`**
   - Finds the next lexicographical permutation of the array `s`:
     - Locates the rightmost string that is smaller than its successor.
     - Identifies the smallest string on the right larger than the identified string.
     - Swaps the two strings and reverses the order of strings to the right.
   - Returns `1` if a next permutation exists or `0` if the array is already in the last permutation.

3. **Main Function**
   - Reads the number of strings (`n`) and the strings themselves.
   - Generates and prints permutations using `next_permutation`.
   - Frees dynamically allocated memory after use.

### **Input/Output**
#### Input
- First line: An integer `n` (number of strings).
- Next `n` lines: Strings with a maximum length of 10 characters each.

#### Output
- All permutations of the input strings, each on a new line.