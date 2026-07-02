class Solution {
public:
    unordered_map<int, int> memo;
    int solve(vector<int>& nums, int target, int sum){
       if(sum == target){
            return 1;
        }
        if(sum > target){
            return 0;
        }

        if (memo.count(sum)) return memo[sum];

        int ways = 0;    
        for(int i = 0; i < nums.size(); i++){

            ways += solve(nums, target, sum+nums[i]);

        }

        return memo[sum] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        int sum = 0;

        return solve(nums, target, sum);

    }
};