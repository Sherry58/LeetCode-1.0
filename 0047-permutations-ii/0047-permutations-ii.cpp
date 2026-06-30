class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(vector<int>& nums, int idx){
        if(idx == n){
            result.push_back(nums);
            return;
        }

        unordered_set<int> st;
        for(int i=idx; i<n; i++){
            if(st.find(nums[i]) != st.end()){
                continue;
            }
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);

            solve(nums, idx+1);

            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        int idx = 0;
        solve(nums, idx);
        return result;
    }
};