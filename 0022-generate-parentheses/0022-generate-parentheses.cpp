class Solution {
public:
    vector<string> result;
    int N;
    
    void solve(string curr, int N, int open, int close){
        if(curr.size() == 2*N){
            result.push_back(curr);
            return;
        }
        if(open < N){
            curr.push_back('(');
            solve(curr,N, open+1, close);
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            solve(curr,N, open, close+1);
            curr.pop_back();
        }
    }
     vector<string> generateParenthesis(int n) {
        N = n;
        string curr = "";
        int open = 0;
        int close = 0;
        solve(curr, n, open, close);
        return result;
    }
};