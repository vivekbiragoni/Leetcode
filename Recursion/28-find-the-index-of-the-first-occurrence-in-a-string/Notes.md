<h2>find-the-index-of-the-first-occurrence-in-a-string Notes</h2><hr>[ Time taken: 12 m 7 s ]

### Submission Notes:

**Title:** Correct Usage of `substr` in `strStr` Implementation

**Description:**
- Implemented a fix in the `strStr` function to correctly find the index of the first occurrence of `needle` in `haystack`.

**Essential Learnings:**

1. **Understanding `substr`:**
   - The `substr` function in C++ is used to obtain a substring from a string.
   - **Syntax:** `string.substr(start_index, length)`
     - `start_index`: The position of the first character to include in the substring.
     - `length`: The number of characters to include in the substring.
   - Example:
     ```cpp
     std::string str = "hello";
     std::string sub = str.substr(1, 3);  // sub will be "ell"
     ```

2. **Common Mistake:**
   - **Incorrect:** Using the ending index instead of the length.
     ```cpp
     std::string sub = str.substr(1, 4);  // This would be incorrect if the intention was to get a substring of length 4 starting at index 1.
     ```
   - **Correct:** Using the length for the second parameter.
     ```cpp
     std::string sub = str.substr(1, 3);  // Correct usage.
     ```

3. **Applying `substr` in `strStr`:**
   - To check if a substring `needle` exists in `haystack`, compare `needle` with `haystack.substr(i, needle.size())`.
   - Ensure the second parameter of `substr` is the length of `needle`.

**Summary:**
This update highlights the correct usage of the `substr` function, ensuring that the second parameter represents the length of the desired substring rather than the ending index. This is crucial for accurate substring extraction and comparison in string manipulation tasks.
