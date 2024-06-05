Counting the number of set bits (1s) in a binary representation of a number can be efficiently done using bit manipulation techniques. One popular algorithm for this is the **Brian Kernighan’s Algorithm**. Here's how it works and a few other methods for comparison:

### 1. Brian Kernighan’s Algorithm
The idea behind this algorithm is to repeatedly flip the least significant set bit to 0 and count how many times this operation is performed.

Here's the implementation:

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // flip the least significant set bit
        count++;
    }
    return count;
}
```

### Explanation:
- The expression `n = n & (n - 1)` removes the rightmost set bit of `n`.
- Each iteration of the loop reduces the number of set bits by one, thus counting the number of set bits.
- This loop runs in O(number of set bits) time, which is very efficient.

### Example:
Consider `n = 13` (binary `1101`):
1. Initial n: `1101` (13)
2. First iteration: `1101 & 1100` = `1100` (12)
3. Second iteration: `1100 & 1011` = `1000` (8)
4. Third iteration: `1000 & 0111` = `0000` (0)

Number of iterations (and thus set bits) = 3.

### 2. Lookup Table Method
For systems where efficiency is critical, a precomputed lookup table can be used. This table is typically an array where each index represents a byte (0-255), and the value at each index is the count of set bits in that byte. This allows for counting set bits in chunks of 8 bits (1 byte) at a time.

```cpp
int lookupTable[256]; // assume this is filled with the count of set bits for each byte

int countSetBits(int n) {
    return lookupTable[n & 0xff] +
           lookupTable[(n >> 8) & 0xff] +
           lookupTable[(n >> 16) & 0xff] +
           lookupTable[(n >> 24) & 0xff];
}
```

### 3. Simple Loop Method
This is a straightforward approach where you check each bit of the integer:

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1); // check if the least significant bit is 1
        n >>= 1; // right shift n by 1 to check the next bit
    }
    return count;
}
```

### Explanation:
- This method iterates over each bit of the number.
- For each bit, it checks if the bit is set (`n & 1`), adds it to the count, and then shifts the number right by one bit.

### Conclusion
The most efficient and commonly used method is Brian Kernighan’s Algorithm due to its O(number of set bits) time complexity, which is generally faster than the simple loop method for numbers with few set bits. The lookup table method can be even faster but requires additional space for the table and is more complex to implement.

Here is the recommended method using Brian Kernighan’s Algorithm:

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // flip the least significant set bit
        count++;
    }
    return count;
}
```
