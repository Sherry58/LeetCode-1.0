class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int>& dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;

        if(dp[idx] != INT_MIN) return dp[idx];

        int pick = nums[idx] + solve(nums, idx-2, dp);
        int notpick = solve(nums, idx-1, dp);

        return dp[idx] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n, INT_MIN);

       return solve(nums, n-1, dp); 
    }
};