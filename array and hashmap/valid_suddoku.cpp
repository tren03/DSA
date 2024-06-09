//The isValidSudoku function in the Solution class validates a Sudoku board by checking rows, columns, and 3x3 sub-boxes for duplicate numbers. It iterates through each row and column using two separate loops, each time checking for duplicates using an unordered_set and clearing the set after each row or column. For the 3x3 sub-boxes, it utilizes three unordered_set<char> in a vector to cover three columns of boxes at a time, clearing these sets every three rows. This ensures that all rows, columns, and sub-boxes are checked for duplicates while maintaining efficient use of memory and processing.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row;
        unordered_set<char> col;
        vector<unordered_set<char>> boxes(3);


        // for row
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    if(row.find(board[i][j])==row.end())
                    {
                        row.insert(board[i][j]);
                    }
                    else
                    {
                        return false;
                    }
                }
                
                
            }
            row.clear();
            
        }

        // for col
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[j][i] == '.')
                {
                    continue;
                }
                else
                {
                    if(col.find(board[j][i])==col.end())
                    {
                        col.insert(board[j][i]);
                    }
                    else
                    {
                        return false;
                    }
                }               
                
            }
            col.clear();
            
        }

        // for box
        int j=0;
        for(int i=0;i<9;i++)
        {
            if(i%3 == 0)
            {
                for(int k=0;k<3;k++)
                {
                    boxes[k].clear();
                }
            }
            for(j=0;j<9;j++)
            {
                int box_no = j/3;

                if(board[j][i] == '.')
                {
                    continue;
                }
                else
                {
                    if(boxes[box_no].find(board[j][i])==boxes[box_no].end())
                    {
                        boxes[box_no].insert(board[j][i]);
                    }
                    else
                    {
                        return false;
                    }
                }   


            }
        }

        return true;

        
    }
};