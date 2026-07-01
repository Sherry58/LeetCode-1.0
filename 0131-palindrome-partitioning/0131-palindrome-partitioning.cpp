class Solution {
public:
    vector<vector<string>> result;
    bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;

            i++;
            j--;
        }
        return true;
    }
    void solve(string& s, int idx, vector<string> curr){
        if(idx == s.size()){
            result.push_back(curr);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));

                solve(s, i+1, curr);

                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int idx = 0;
        vector<string> curr = {};

        solve(s, idx, curr);

        return result;
    }
};