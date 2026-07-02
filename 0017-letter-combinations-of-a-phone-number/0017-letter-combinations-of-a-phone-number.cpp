class Solution {
public:
    vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> results;
    void solve(string& digits, vector<string>& map, int idx, string& curr){
        if(idx >= digits.size()){
            results.push_back(curr);
            return;
        }

        string letters = map[digits[idx] - '0'];

        for(int i = 0; i < letters.size(); i++){

            curr.push_back(letters[i]);

            solve(digits, map, idx+1, curr);

            curr.pop_back();
        }
    } 
    vector<string> letterCombinations(string digits) {
        int idx = 0; string curr = "";
        
         if(digits.empty()) return {};

        solve(digits, map, idx, curr);

        return results;

    }
};