class Solution {
public:
    vector<vector<string>> result;
    int N;
    unordered_set<int> Cols;
    unordered_set<int> Diag;
    unordered_set<int> AntiDiag;


    void solve(vector<string>& board, int row) {
        if (row >= N) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < N; col++) {
            int DiagConst = row+col;
            int AntiDiagConst = row-col;

            if(Cols.find(col)!=Cols.end() or Diag.find(DiagConst)!=Diag.end() or AntiDiag.find(AntiDiagConst)!=AntiDiag.end()){
                continue;
            }
            Cols.insert(col);
            Diag.insert(DiagConst);
            AntiDiag.insert(AntiDiagConst);
            board[row][col] = 'Q';

            solve(board, row+1);

            Cols.erase(col);
            Diag.erase(DiagConst);
            AntiDiag.erase(AntiDiagConst);
            board[row][col] = '.'; 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(N, string(N, '.'));
        solve(board, 0);
        return result;
    }
};