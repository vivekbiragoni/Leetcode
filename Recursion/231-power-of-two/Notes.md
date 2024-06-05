<h2>power-of-two Notes</h2><hr>[ Time taken: 4 m 5 s ]
The method you have provided is quite efficient for determining if a number is a power of two. Let's break it down:

### Explanation:
1. **Check if \( n \) is less than 1**: If \( n \) is less than 1, it can't be a power of two.
2. **Bitwise AND operation**: The expression `(n & (n-1)) == 0` is used to check if \( n \) is a power of two.
   - This works because powers of two in binary representation have exactly one bit set to 1 (e.g., 1 is 2^0, 2 is 2^1, 4 is 2^2, 8 is 2^3, etc.).
   - When you subtract 1 from a power of two, all bits after the only set bit (inclusive) are flipped. For example:
     - \( n = 4 \) (binary `100`), \( n-1 = 3 \) (binary `011`).
     - The bitwise AND of \( n \) and \( n-1 \) will be `000`.
   - Hence, for a number that is a power of two, `(n & (n-1))` will be zero.

### Alternative Methods:
While your method is already optimal in terms of time complexity (O(1)), we can explore a couple of other methods for educational purposes:

#### 1. Using a Loop:
This method is less efficient but straightforward:

```cpp
bool isPowerOfTwo(int n) {
    if (n < 1) return false;
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}
```

This method repeatedly divides \( n \) by 2 until \( n \) is no longer divisible by 2. If \( n \) becomes 1, it was a power of two.

#### 2. Using Bit Count:
You can also use a built-in function to count the number of set bits (1s) in the binary representation of \( n \). For a power of two, this count should be exactly 1.

```cpp
#include <bitset>

bool isPowerOfTwo(int n) {
    if (n < 1) return false;
    return std::bitset<32>(n).count() == 1;
}
```

However, this method is not more efficient than the bitwise method you used; it simply demonstrates another way to achieve the same goal.

### Conclusion:
Your original method using `(n & (n-1)) == 0` is one of the most efficient ways to determine if a number is a power of two in terms of both time complexity and simplicity. It performs in constant time O(1) and is easy to understand. Therefore, there is no more efficient way than this in terms of computational complexity.
