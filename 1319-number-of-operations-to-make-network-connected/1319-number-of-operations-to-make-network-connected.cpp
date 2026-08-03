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
    int makeConnected(int n, vector<vector<int>>& connections) {

        parent.assign(n,0);
        rank.assign(n,0);

        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        if(connections.size() < n-1) return -1;

        int components = n;
        int extra = 0;

        for(auto &e: connections){
            int u = e[0];
            int v = e[1];

            int u_parent = find(u);
            int v_parent = find(v);

            if(u_parent == v_parent) extra++;

            else{
                Union(u,v);
                components--;
            }
        }

        if(extra >= components-1)  return components-1;
        else return -1;
    }
};