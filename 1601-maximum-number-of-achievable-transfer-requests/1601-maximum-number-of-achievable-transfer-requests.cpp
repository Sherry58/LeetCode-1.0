class Solution {
public:
    int result = INT_MIN;
    void solve(vector<vector<int>>& requests, int idx, int count, vector<int>& office){
        if(idx >= requests.size()){
            bool allZero = true;

            for(int &x : office){
                if(x != 0){
                    allZero = false;
                    break;
                }
            }
            if(allZero == true){
                result = max(result, count);
            }

            return;
        }
        int from = requests[idx][0];
        int to = requests[idx][1];

        office[from]--;
        office[to]++;

        solve(requests, idx+1, count+1, office);

        office[from]++;
        office[to]--;

        solve(requests,idx+1, count, office);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int idx = 0;
        int count = 0;
        vector<int> office(n,0);
        
        solve(requests, idx, count, office);

        return result;
    }
};