### Problem: Count Good Numbers

Given a digit string \( s \) of length \( n \), we need to count the number of "good" digit strings. A digit string is considered "good" if:
- Digits at even indices are even.
- Digits at odd indices are prime (2, 3, 5, 7).

The result should be returned modulo \( 10^9 + 7 \).

### Example

- **Input**: n = 4
- **Output**: 400
- **Explanation**: The good numbers of length 4 include all combinations of even digits (0, 2, 4, 6, 8) at even indices and prime digits (2, 3, 5, 7) at odd indices.

### Constraints
- \( 1 \leq n \leq 10^{15} \)

### Solution Explanation

The solution uses modular exponentiation to efficiently compute large powers under a modulus.

1. **Counting Choices**:
   - There are 5 choices (0, 2, 4, 6, 8) for each even position.
   - There are 4 choices (2, 3, 5, 7) for each odd position.

2. **Number of Even and Odd Indexed Positions**:
   - \( \text{count\_of\_5s} \): Number of even indexed positions \( = \lceil \frac{n}{2} \rceil \).
   - \( \text{count\_of\_4s} \): Number of odd indexed positions \( = \lfloor \frac{n}{2} \rfloor \).

3. **Modular Exponentiation**:
   - Computes the powers \( 5^{\text{count\_of\_5s}} \) and \( 4^{\text{count\_of\_4s}} \) modulo \( 10^9 + 7 \).

### Solution Code

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    long long power(long long x, long long y) {
        long long res = 1;
        x = x % mod;  // Ensure base is within the modulus range

        if (x == 0) return 0;  // If base is 0, result is 0

        while (y > 0) {
            if (y & 1) {  // If y is odd
                res = (res * x) % mod;  // Multiply result with current base
            }
            y = y >> 1;  // Divide y by 2
            x = (x * x) % mod;  // Square the base and take mod
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
        long long count_of_4s = n / 2;  // Number of odd index positions
        long long count_of_5s = (n - count_of_4s);  // Number of even index positions

        // Compute 5^count_of_5s % mod
        long long part1 = power(5LL, count_of_5s);
        // Compute 4^count_of_4s % mod
        long long part2 = power(4LL, count_of_4s);

        // Multiply the two results and take mod again to ensure result within range
        long long ans = (part1 * part2) % mod;

        return (int)ans;  // Return as integer
    }
};
```

### Key Takeaways

1. **Modular Arithmetic**: Ensures calculations remain within the bounds of typical data types, avoiding overflow.
2. **Efficient Exponentiation**: Uses the method of repeated squaring to compute large powers efficiently.
3. **Handling Large Inputs**: The solution efficiently handles very large values of \( n \) (up to \( 10^{15} \)).

### Submission Notes

1. **Problem Understanding**: Grasp the constraints and requirements of counting "good" digit strings based on specific rules.
2. **Optimized Approach**: Use modular exponentiation for efficiency with large inputs.
3. **Edge Cases**: Consider scenarios where \( n \) is small or large, ensuring the solution handles these correctly.
