class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums, int idx, vector<int>& curr){
        if(curr.size() >= 2){
            result.push_back(curr);
        }

        unordered_set<int> st;
        for(int i = idx; i < nums.size(); i++){
            if((curr.empty() or nums[i] >= curr.back()) and st.find(nums[i]) == st.end()){

                st.insert(nums[i]);

                curr.push_back(nums[i]);
                solve(nums, i+1, curr);
                curr.pop_back();
                
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         
        int idx = 0;
        vector<int> curr = {};

        solve(nums, idx, curr);

        return result;
    }
};