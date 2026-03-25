class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int n){
        for(int i=0; i<col; i++){
            if(board[row][i]=='Q') return false;
        }
        for(int i=row, j= col; i>=0 && j>=0; i--,j-- )//upper left diagonal
        {
            if(board[i][j]=='Q') return false;
        }
        for(int i=row, j= col; i<n && j>=0; i++,j-- )//lower left diagonal
        {
            if(board[i][j]=='Q') return false;
        }
        for(int i=row, j = col; i>=0 && j<n; i--,j++ )//upper right diagonal
        {
            if(board[i][j]=='Q') return false;
        }
        for(int i=row, j = col; i<n && j<n; i++,j++ )//lower right diagonal
        {
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(int n, vector<vector<char>>& board, vector<vector<string>>& ans, int col){
        if(col==n){
            vector<string>temp;
            for(int i=0; i<n;i++){
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row, col,board,n)){
                board[row][col]='Q';
                solve(n, board, ans, col+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>> board(n, vector<char>(n,'.'));
        solve(n, board, ans,0);
        return ans;
    }
};