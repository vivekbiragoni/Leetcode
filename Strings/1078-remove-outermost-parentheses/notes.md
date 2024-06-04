### Submission Notes:

**Title:** Removing Outermost Parentheses from Valid Parentheses String

**Description:**
- Implemented a function `removeOuterParentheses` to remove the outermost parentheses from each primitive part of a valid parentheses string.
- Utilized a stack to keep track of the depth of parentheses.

**Essential Learnings:**

1. **Primitive Valid Parentheses Strings:**
   - A valid parentheses string is primitive if it cannot be split into two nonempty valid parentheses strings.
   - Example: `(()())` and `(())` are primitive parts of `(()())(())`.

2. **Using Stack to Track Depth:**
   - A stack helps manage nested parentheses by pushing on open parentheses `(` and popping on close parentheses `)`.
   - This allows tracking of when a set of parentheses is fully closed.

3. **Removing Outermost Parentheses:**
   - For each open parenthesis `(`, add it to the result only if the stack is not empty before pushing.
   - For each close parenthesis `)`, add it to the result only if the stack is not empty after popping.

### Detailed Explanation of Code:

- **Stack Initialization:** 
  - `stack<char> st;` to keep track of open parentheses.
  - `string res;` to store the final result without outer parentheses.

- **Iterate through String:**
  - For each character `c` in the string `s`:
    - If `c` is an open parenthesis `(`:
      - Check if the stack is not empty, meaning it's not an outer parenthesis.
      - Push the open parenthesis onto the stack.
    - If `c` is a close parenthesis `)`:
      - Pop from the stack.
      - Check if the stack is not empty after popping, meaning it's not an outer parenthesis.
      - Add the character to the result accordingly.

