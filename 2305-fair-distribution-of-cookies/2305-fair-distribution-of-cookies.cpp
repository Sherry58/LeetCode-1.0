class Solution {
public:
    int result = INT_MAX;
    int n;

    void solve(vector<int>& cookies, vector<int>& children, int idx, int k){
        if(idx == cookies.size()){

            int unfairness = *max_element(children.begin(), children.end());
            result = min(result, unfairness);

            return;
        }
        int cookie = cookies[idx];

        for(int i = 0; i < k; i++){

            children[i] += cookie;

            solve(cookies, children, idx+1, k);

            children[i] -= cookie; 
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int> children(k,0);
        int idx = 0;

        solve(cookies, children, idx, k);

        return result;
    }
};