 The logic of finding the next permutation of a number array. The next permutation of an array is the lexicographically next greater permutation of its elements. Here’s a step-by-step process to achieve this:

### Step-by-Step Logic:

1. **Identify the Longest Non-Increasing Suffix**:
   - Start from the end of the array and find the first pair of consecutive elements `nums[i]` and `nums[i-1]` where `nums[i] > nums[i-1]`. This identifies the part of the array that needs to be rearranged to get the next permutation.

2. **Find the Pivot Element**:
   - The element just before this suffix (`nums[i-1]`) is called the pivot. If no such element exists, it means the entire array is non-increasing, and thus, the current permutation is the last permutation. In this case, reverse the array to get the first permutation.

3. **Find the Rightmost Successor to the Pivot**:
   - Scan the elements to the right of the pivot (`nums[i-1]`) to find the smallest element that is greater than the pivot. This element will be swapped with the pivot to increase the permutation slightly.

4. **Swap the Pivot with the Rightmost Successor**:
   - Swap the pivot with this rightmost element found in the previous step.

5. **Reverse the Suffix**:
   - Reverse the suffix starting at the position `i` to get the next smallest lexicographic permutation. This step ensures that the suffix is in the smallest possible order.

### Example:

Let's go through an example step-by-step.

#### Example Array: [1, 2, 3]

- **Step 1**: Identify the longest non-increasing suffix. Here, the suffix is [3].
- **Step 2**: The pivot is the element before this suffix, which is 2.
- **Step 3**: Find the rightmost successor to the pivot in the suffix. The smallest element greater than 2 in the suffix is 3.
- **Step 4**: Swap the pivot (2) with 3. The array becomes [1, 3, 2].
- **Step 5**: Reverse the suffix [2], which remains [2]. The final array is [1, 3, 2].

### Algorithm Pseudocode:

Here is the pseudocode for better understanding:

1. Find the largest index `k` such that `nums[k] < nums[k+1]`. If no such index exists, the permutation is the last permutation.
2. Find the largest index `l` greater than `k` such that `nums[k] < nums[l]`.
3. Swap the value of `nums[k]` with that of `nums[l]`.
4. Reverse the sequence from `nums[k+1]` up to and including the final element `nums[nums.size() - 1]`.

### Explanation of Edge Cases:

- If the array is already the highest permutation (e.g., [3, 2, 1]), step 1 will not find a valid `k`. In this case, the array is reversed to get the lowest permutation.

### Applying the Algorithm:

For an array `nums = [1, 3, 2]`:

1. Find `k` such that `nums[k] < nums[k+1]`. Here, `k = 0` (nums[0] = 1, nums[1] = 3).
2. Find `l` such that `nums[k] < nums[l]`. Here, `l = 2` (nums[2] = 2).
3. Swap `nums[k]` with `nums[l]`. The array becomes [2, 3, 1].
4. Reverse the sequence from `nums[k+1]` to the end. The array becomes [2, 1, 3].

By following this algorithm, you can find the next permutation of any given array in an efficient manner.
