class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        const vector<pair<int, int>> directions = { {1,0},{-1,0},{0,1},{0,-1} };
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 0) continue;

                int size = 0;
                queue<pair<int, int>> nextElements;
                nextElements.push({ i,j });

                while (!nextElements.empty())
                {
                    int sizeQueue = nextElements.size();
                    for (int i = 0; i < sizeQueue; i++)
                    {
                        pair<int, int> currentElement = nextElements.front();
                        nextElements.pop();

                        int currentRow = currentElement.first;
                        int currentCol = currentElement.second;

                        grid[currentRow][currentCol] = 0;
                        size++;

                        for (pair<int, int> dir : directions)
                        {
                            int newRow = currentRow + dir.first;
                            int newCol = currentCol + dir.second;

                            if (
                                min(newRow, newCol) < 0 ||
                                newRow == rows ||
                                newCol == cols ||
                                grid[newRow][newCol] == 0 ||
                                visited[newRow][newCol] == true
                                ) continue;

                            visited[newRow][newCol] = true;
                            nextElements.push({ newRow, newCol });
                        }
                    }
                }
                maxSize = max(size, maxSize);
            }
        }
        return maxSize;
    }
};
