class Solution {
public:
    vector<vector<int>> result;

    void solve(int idx, int n ,int k , vector<int>& curr){
        if(curr.size() == k){

            result.push_back(curr);

            return;
        }

        for(int i = idx; i <= n; i++){

            curr.push_back(i);

            solve(i+1, n, k, curr);

            curr.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
       int idx = 1;
       vector<int> curr ={};
        solve(idx, n, k, curr);

        return result;
    }
};