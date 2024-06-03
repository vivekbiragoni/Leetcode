Submission Notes for `myAtoi` Implementation

### Overview

The provided code implements a custom version of the `atoi` function, commonly known as `myAtoi`. This function converts a string representation of a number into an integer, taking into account the sign of the number and the limits of the integer type. The implementation is encapsulated within a class named `Solution`, which includes private helper methods for trimming whitespace, detecting the sign of the number, and extracting digits from the string.

### Key Components

1. **Trim Function**: The `trim` function is responsible for removing leading whitespaces from the input string. It uses recursion to skip over spaces until it encounters a non-space character or reaches the end of the string. This function is crucial for preparing the input string for further processing.

2. **Detect Sign Function**: The `detect_sign` function analyzes the input string to determine whether the number represented is positive or negative. It returns a pair consisting of an integer sign (`1` for positive, `-1` for negative) and the remaining part of the string after the sign. This function is essential for correctly interpreting the sign of the number.

3. **Extract Digits Function**: The `extract_digits` function extracts a sequence of digits from the input string, starting from a specified position. It uses recursion to build up the sequence of digits from right to left. This function is key to converting the string representation of the number into a numeric value.

4. **Main Conversion Logic**: The `myAtoiHelper` function orchestrates the conversion process. It first trims the input string, detects the sign, extracts the digits, and then constructs the final numeric result. It handles overflow by checking if the constructed number exceeds the limits of the `int` type and returns the appropriate limit value accordingly.

5. **Public Interface**: The public `myAtoi` function serves as the entry point for the conversion process. It delegates the actual work to the `myAtoiHelper` function, providing a clean interface for users of the `Solution` class.

### Clarification Questions Addressed

- **Why use `size_t` for loop counters and indices?**
  - The use of `size_t` ensures safety and portability when dealing with sizes and indices, especially in contexts involving dynamic sizes like strings or arrays.

- **Why is `substr` used in the `trim` function?**
  - The `substr` method is used to efficiently extract portions of the string, allowing the `trim` function to remove leading whitespaces without manual copying or manipulation of characters.

- **Why is `start` of type `size_t` in the `detect_sign` function?**
  - Using `size_t` for the `start` parameter ensures that the function can safely handle positions within the string, avoiding potential issues with negative indices or overflow.

- **Should `i` in for-loops be replaced with `size_t`?**
  - Replacing `int` with `size_t` for loop counters can improve safety and portability, especially when iterating over collections or arrays where the size might exceed the range of a signed integer.

### Conclusion

This implementation of `myAtoi` demonstrates a thoughtful approach to parsing and converting string representations of numbers, incorporating best practices for safety, efficiency, and readability. The use of helper functions modularizes the code, making it easier to understand and maintain.
