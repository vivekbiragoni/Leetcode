

### Problem Description
Given an `m x n` matrix `matrix`, if an element in the matrix is `0`, set its entire row and column to `0`. Modify the matrix in-place.

### Example
- **Input**: `matrix = [[1,1,1],[1,0,1],[1,1,1]]`
  - **Output**: `[[1,0,1],[0,0,0],[1,0,1]]`
  - Explanation: The element at position `matrix[1][1]` is `0`, so its entire row and column are set to `0`.

- **Input**: `matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]`
  - **Output**: `[[0,0,0,0],[0,4,5,0],[0,3,1,0]]`
  - Explanation: The elements at positions `matrix[0][0]` and `matrix[2][3]` are `0`, so their respective rows and columns are set to `0`.

### Constraints
- `1 <= m, n <= 200`
- `-2^31 <= matrix[i][j] <= 2^31 - 1`

### Approach
1. **Identify Zero Positions**: Use boolean flags (`firstRowZero` and `firstColZero`) to track if the first row and column need to be zeroed out based on the presence of `0` in their respective rows or columns.
  
2. **Marking Process**:
   - Traverse the matrix and use the first row and column to mark which rows and columns need to be zeroed out. Use the first row and first column as markers.

3. **Apply Zeroing**:
   - Iterate through the matrix again (starting from the second row and column) and set the cell to `0` if its corresponding marker (in the first row or column) is `0`.

4. **Handle First Row and Column**:
   - Based on the boolean flags, zero out the entire first row and column if necessary.

### Implementation
Here's the implementation encapsulated in a `Solution` class in C++:

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();  // number of rows
        int n = matrix[0].size();  // number of columns

        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if the first row has any zero
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // Check if the first column has any zero
        for(int j = 0; j < m; j++){
            if(matrix[j][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use the first row and column to mark zeros
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to zero based on the markers in the first row and column
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if(firstRowZero){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }

        // Zero out the first column if needed
        if(firstColZero){
            for (int j = 0; j < m; j++){
                matrix[j][0] = 0;
            }
        }
    }
};
```

### Notes:
- **Time Complexity**: \(O(m \times n)\) where \(m\) is the number of rows and \(n\) is the number of columns. This is because we traverse the matrix a few times, but each cell is processed in constant time.
  
- **Space Complexity**: \(O(1)\) additional space, as we only use a few extra variables regardless of the input size.

- **Edge Cases**: Handle cases with zeros in the first row, first column, or both, ensuring the entire matrix is correctly zeroed out where necessary.

This approach efficiently modifies the matrix in-place while respecting the constraints and edge cases provided by the problem statement.
