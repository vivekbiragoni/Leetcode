<h2>generate-parentheses Notes</h2><hr>[ Time taken: 8 m 24 s ]

To approach the problem of generating all combinations of well-formed parentheses using recursion, follow these steps:

1. **Identify Base Cases**:
   - Determine the simplest possible input(s) for which the solution is known without recursion.
   - In this problem, when `n = 0`, the only valid combination is an empty string, so this is the base case.

2. **Define Recursive Cases**:
   - Identify how to break down the problem into smaller, simpler versions of the same problem.
   - Each valid combination of well-formed parentheses can be constructed by appending '(' or ')' to existing combinations, subject to certain constraints:
     - The number of '(' cannot exceed `n`.
     - ')' can only be added if there are more '(' than ')'.

3. **Plan Recursion**:
   - Define a recursive function that takes parameters representing the current combination of parentheses, the count of '(' and ')', and the maximum allowed count of parentheses (`n`).
   - At each recursive call, explore appending '(' and ')' to the current combination if it doesn't violate the constraints mentioned above.

4. **Combine Solutions**:
   - Combine the solutions obtained from recursive calls to construct the final list of valid combinations.

Here's how you can implement these steps in C++:

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParenthesesHelper(int n, int open, int close, string current, vector<string>& result) {
    // Base case: When all parentheses are used
    if (open == n && close == n) {
        result.push_back(current);
        return;
    }

    // Recursive cases:
    // Add '(' if the count of '(' is less than n
    if (open < n) {
        generateParenthesesHelper(n, open + 1, close, current + '(', result);
    }
    // Add ')' if the count of ')' is less than '('
    if (close < open) {
        generateParenthesesHelper(n, open, close + 1, current + ')', result);
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    generateParenthesesHelper(n, 0, 0, "", result);
    return result;
}

int main() {
    int n = 3;
    vector<string> combinations = generateParentheses(n);
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}
```

This code generates all combinations of well-formed parentheses for a given `n` using recursion. It follows the steps outlined above, ensuring that each combination maintains the validity of the parentheses. Run the code with different values of `n` to see how it generates the corresponding combinations.
