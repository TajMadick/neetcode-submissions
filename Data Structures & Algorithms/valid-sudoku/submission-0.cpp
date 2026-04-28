class Solution {
public:
    int calcSubBox(int row, int col)
    {
        int box = 0;

        box += (col / 3);
        box += (row / 3) * 3;

        return box;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, unordered_set<char>> taken; 
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int subBox = calcSubBox(i, j);
                    if (taken["0" + to_string(i)].count(board[i][j]) ||
                        taken["1" + to_string(j)].count(board[i][j]) ||
                        taken["2" + to_string(subBox)].count(board[i][j])
                    )
                    {
                        return false;
                    }
                    else
                    {
                        taken["0" + to_string(i)].insert(board[i][j]);
                        taken["1" + to_string(j)].insert(board[i][j]);
                        taken["2" + to_string(subBox)].insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};
