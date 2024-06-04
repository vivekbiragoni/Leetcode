
### Submission Notes

#### Problem Statement:
The task is to find the largest odd number formed by the digits of a given string.

#### Solution Logic:
1. **Looping Backwards through the String:**
   - The code iterates from the last character of the string `nums` to the first character, examining each digit from right to left.

2. **Checking for Oddness:**
   - Within each iteration of the loop, it checks if the current digit is odd.
   - `(nums[i] - '0') % 2 == 1` calculates the remainder when the numeric value of the current character is divided by 2. If this remainder is 1, then the digit is odd.

3. **Returning the Largest Odd Number:**
   - When an odd digit is found, it returns the substring of `nums` from the beginning up to (and including) the current position.
   - This ensures that the returned string contains the largest odd number formed by the digits of the input string.

4. **Returning an Empty String if No Odd Digit is Found:**
   - If no odd digit is found after iterating through the entire string, it returns an empty string `""`.
   - This indicates that there are no odd digits in the input string.

#### Clarifications:
- The original condition `(int)nums[nums.size()-1]%2 == 1` was corrected to `(nums[i] - '0') % 2 == 1` to accurately determine if the current digit is odd.
- The main logic involves iterating through the string from right to left, checking each digit's oddness, and returning the appropriate substring to form the largest odd number.

