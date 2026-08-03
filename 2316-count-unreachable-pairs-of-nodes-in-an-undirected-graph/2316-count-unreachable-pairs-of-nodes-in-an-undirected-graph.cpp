class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(x == parent[x]) return x;
        
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent){
            return;
        }
        else{
            if(rank[x_parent] > rank[y_parent]){
                parent[y_parent] = x_parent;
            }
            else if(rank[x_parent] < rank[y_parent]){
                parent[x_parent] = y_parent;
            }
            else{
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.assign(n,0);
        rank.assign(n,0);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int components = n;
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            Union(u,v);
        }

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int parent_i = find(i);
            mp[parent_i]++;
        }

        long long ans = 0;
        long long remsize = n;

        for(auto &it : mp){
            long long currsize = it.second;
            
            remsize -= currsize;
            ans += 1LL*currsize * remsize;
        } 
            
        return ans;
    }
};