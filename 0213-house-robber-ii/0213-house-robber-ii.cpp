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
        if(n == 1) return nums[0];

        vector<int> first(nums.begin(), nums.end()-1);
        vector<int> last(nums.begin()+1, nums.end());

        vector<int> dp1(n-1, INT_MIN);
        vector<int> dp2(n-1, INT_MIN);

        int case1 = solve(first, n-2, dp1);
        int case2 = solve(last, n-2, dp2);

        return max(case1, case2);
    }
};