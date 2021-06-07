class Solution {
public:
    vector<vector<int>>directions = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>>result = board;
        
        int M = board.size();
        int N = board[0].size();
        
        for(int i = 0 ; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                int count = 0;
                
                for(auto dir:directions)
                {
                    int x = dir[0] + i;
                    int y = dir[1] + j;
                    
                    if(x < 0 || y < 0 || x >= result.size() || y >= result[0].size())
                    {
                        continue;
                    }

                    if(board[x][y]) count++;
                    
                    //Put the conditions 
                    if(count < 2)
                    {
                        board[i][j] = 0;
                    }
                    else if(count == 2 || count == 3)
                    {
                        board[i][j] = 1;
                    }
                    else if(count > 3)
                    {
                        board[i][j] = 0;
                    }
                    else if(count == 3)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }
        
        
        
         
    }
};
