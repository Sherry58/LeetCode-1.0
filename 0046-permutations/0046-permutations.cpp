class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums, int idx){
        int n = nums.size();
        if(idx >= n){
            result.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            swap(nums[i], nums[idx]);
            solve(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int idx=0;
        solve(nums, idx);

        return result;

    }
};