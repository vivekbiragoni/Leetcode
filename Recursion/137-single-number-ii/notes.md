### Notes for Finding the Unique Element in an Array Where All Others Appear Thrice

The problem is to find a single element in an array where every other element appears exactly three times. We use bitwise operations to solve this efficiently.

### Key Concepts:

1. **Bitwise Counting**:
   - We use an array `bitCount` to count the number of times each bit (from 0 to 31) is set across all numbers.
   - Since integers are represented using 32 bits, the array size is 32.

2. **Bit Manipulation**:
   - Using bitwise operators, we can isolate and count specific bits of each number.
   - `(num >> i) & 1` isolates the `i`-th bit of `num`.

### Code Explanation:

```cpp
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // This array will hold the sum of bits at each position
        int bitCount[32] = {0};
        
        // Count the sum of bits at each position
        for(int num : nums) {
            for(int i = 0; i < 32; ++i) {
                bitCount[i] += (num >> i) & 1;
            }
        }
        
        // Reconstruct the single number from bit counts
        int result = 0;
        for(int i = 0; i < 32; ++i) {
            if (bitCount[i] % 3 != 0) {
                result |= (1 << i);
            }
        }
        
        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 2};
    cout << sol.singleNumber(nums) << endl; // Output: 3

    nums = {0, 1, 0, 1, 0, 1, 99};
    cout << sol.singleNumber(nums) << endl; // Output: 99

    return 0;
}
```

### Detailed Explanation:

#### First For Loop: Counting Bits

```cpp
for(int num : nums) {
    for(int i = 0; i < 32; ++i) {
        bitCount[i] += (num >> i) & 1;
    }
}
```

- **Outer Loop (`for(int num : nums)`)**:
  - Iterates over each number in the input array `nums`.
  
- **Inner Loop (`for(int i = 0; i < 32; ++i)`)**:
  - Iterates over each bit position from 0 to 31.
  - `(num >> i) & 1`: 
    - `num >> i`: Shifts the bits of `num` to the right by `i` positions.
    - `& 1`: Isolates the least significant bit of the shifted number.
  - `bitCount[i] += (num >> i) & 1`: Increments the count of the `i`-th bit by 1 if it is set (i.e., equals 1).

#### Second For Loop: Reconstructing the Unique Number

```cpp
int result = 0;
for(int i = 0; i < 32; ++i) {
    if (bitCount[i] % 3 != 0) {
        result |= (1 << i);
    }
}
```

- **Initialization**:
  - `result` is initialized to 0, which will store the unique number.

- **For Loop (`for(int i = 0; i < 32; ++i)`)**:
  - Iterates over each bit position from 0 to 31.
  - `if (bitCount[i] % 3 != 0)`:
    - Checks if the count of the `i`-th bit is not a multiple of 3.
    - Since all other numbers appear three times, their bits will contribute counts that are multiples of 3.
    - If the count is not a multiple of 3, it means this bit belongs to the unique number.
  - `result |= (1 << i)`:
    - `1 << i`: Creates a mask with the `i`-th bit set.
    - `result |= ...`: Sets the `i`-th bit in `result` if the condition is true.

### Summary

1. **Counting Bits**:
   - Iterate through each number and each bit position to count the number of times each bit is set.

2. **Reconstructing the Unique Number**:
   - Check each bit count modulo 3 to determine which bits belong to the unique number.
   - Set the corresponding bits in the result.

This method leverages bit manipulation to efficiently find the unique element that appears once while all others appear three times, with a time complexity of \(O(n)\) and space complexity of \(O(1)\).
