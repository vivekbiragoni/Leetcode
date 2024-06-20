<h2>rotting-oranges Notes</h2><hr>[ Time taken: 1 hr 24 m 6 s ]



### Problem: Rotting Oranges

**Problem Description:**
- Given an `m x n` grid where each cell can have:
  - `0` representing an empty cell,
  - `1` representing a fresh orange,
  - `2` representing a rotten orange.
- Fresh oranges adjacent (4-directionally) to rotten oranges become rotten every minute.
- Determine the minimum number of minutes until no fresh oranges remain. Return `-1` if it's impossible.

**Example:**
- Input: `grid = [[2,1,1],[1,1,0],[0,1,1]]`
  - Output: `4`
  - Explanation: It takes 4 minutes for all oranges to become rotten.

**Constraints:**
- `1 <= m, n <= 10`
- `grid[i][j]` is `0`, `1`, or `2`.

### Approach: BFS (Breadth-First Search)

**Steps to Solve:**

1. **Initialization:**
   - Initialize variables:
     - `rotten`: Queue to store coordinates of rotten oranges.
     - `freshOranges`: Count of fresh oranges initially present.

2. **Enqueue Rotten Oranges:**
   - Traverse the grid to:
     - Enqueue coordinates of rotten oranges (`grid[i][j] == 2`) into `rotten`.
     - Count fresh oranges (`grid[i][j] == 1`).

3. **BFS Execution:**
   - Define 4-directional movements (`up`, `down`, `left`, `right`).
   - Use a `while` loop to process each level (or minute):
     - Get the current size of `rotten` (`size`).
     - Process each orange in `rotten`:
       - Dequeue an orange and attempt to rot adjacent fresh oranges.
       - Mark them as rotten (`grid[nx][ny] = 2`) and enqueue them.
       - Decrement `freshOranges` as oranges turn rotten.

4. **Edge Case Handling:**
   - After BFS traversal:
     - If `freshOranges > 0`, return `-1` (some oranges remain fresh).
     - Else, return the number of minutes passed.

**Code Implementation:**

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> rotten;
        int freshOranges = 0;
        
        // Enqueue all rotten oranges and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        
        // Directions for 4-directional movement (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int minutes = 0;
        
        while (!rotten.empty() && freshOranges > 0) {
            int size = rotten.size(); // Get the current size of the queue
            
            for (int k = 0; k < size; ++k) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                
                for (auto& dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        // Rot the fresh orange
                        grid[nx][ny] = 2;
                        rotten.push({nx, ny});
                        freshOranges--;
                    }
                }
            }
            
            minutes++;
        }
        
        // After BFS traversal, if there are still fresh oranges left, return -1
        if (freshOranges > 0) {
            return -1;
        } else {
            return minutes;
        }
    }
};

int main() {
    Solution sol;
    
    // Example usage
    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Output for grid1: " << sol.orangesRotting(grid1) << endl; // Output: 4
    
    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << "Output for grid2: " << sol.orangesRotting(grid2) << endl; // Output: -1
    
    vector<vector<int>> grid3 = {{0,2}};
    cout << "Output for grid3: " << sol.orangesRotting(grid3) << endl; // Output: 0
    
    return 0;
}
```

**Notes:**

- **BFS Advantages**: BFS is suitable due to its level-wise traversal nature, which matches the requirement of tracking minutes in this problem.
- **Queue Usage**: Utilizing a queue (`rotten`) helps manage the order of processing oranges, ensuring each minute is processed correctly.
- **Edge Cases**: Handled by checking `freshOranges` after BFS completes to determine if all oranges were successfully rotten or if some remained fresh.

