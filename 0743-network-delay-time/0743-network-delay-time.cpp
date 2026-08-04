class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &t : times){
            int u = t[0]-1, v = t[1]-1, w = t[2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);

        k--;
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            if(d > dist[node]) continue;

            for(int i = 0; i < adj[node].size(); i++){
                int nbr = adj[node][i].first;
                int wt = adj[node][i].second;

                if(d+wt < dist[nbr]){
                    dist[nbr] = d+wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        int res = *max_element(dist.begin(), dist.end());

        if(res == INT_MAX) return -1;

        return res;
        
    }
};