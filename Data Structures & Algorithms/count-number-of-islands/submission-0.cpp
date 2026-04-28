class Solution {
public:
    void eraseIsland(vector<vector<char>>& grid, pair<int, int> currentField,
    vector<pair<int, int>>& directions)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> nextFields;
        nextFields.push(currentField);

        while (!nextFields.empty())
        {
            int sizeQueue = nextFields.size();

            for (int i = 0; i < sizeQueue; i++)
            {
                pair<int, int> currentField = nextFields.front();
                nextFields.pop();

                int currentRow = currentField.first;
                int currentCol = currentField.second;

                grid[currentRow][currentCol] = '0';

                for (pair<int, int> dir : directions)
                {
                    int newRow = currentRow + dir.first;
                    int newCol = currentCol + dir.second;

                    if (min(newRow, newCol) < 0 ||
                        newRow == rows ||
                        newCol == cols ||
                        grid[newRow][newCol] == '0'
                        ) continue;

                    nextFields.push({ newRow, newCol });
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> nextFields;
        vector<pair<int, int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1} };

        nextFields.push({ 0,0 });

        while (!nextFields.empty())
        {
            int sizeQueue = nextFields.size();

            for (int i = 0; i < sizeQueue; i++)
            {
                pair<int, int> currentField = nextFields.front();
                nextFields.pop();

                int currentRow = currentField.first;
                int currentCol = currentField.second;

                if (grid[currentRow][currentCol] == '1')
                {
                    counter++;
                    eraseIsland(grid, currentField, directions);
                }

                for (pair<int, int> dir : directions)
                {
                    int newRow = currentRow + dir.first;
                    int newCol = currentCol + dir.second;

                    if (min(newRow, newCol) < 0 ||
                        newRow == rows ||
                        newCol == cols ||
                        visited[newRow][newCol] == true
                        ) continue;

                    visited[newRow][newCol] = true;
                    nextFields.push({ newRow, newCol });
                }
            }
        }

        return counter;
    }
};
