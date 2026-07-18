class Solution {
public:
    void DFS(vector<vector<int>> &adj, int u, vector<bool>& visited){

        visited[u] = true;

        for(auto& v : adj[u]){

            if(visited[v] == false){

                DFS(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int N = isConnected.size();

        vector<vector<int>> adj(N);
        vector<bool> visited(N, false);

        for(int i = 0; i<N ; i++){
            for(int j = 0; j<N; j++){
                if(isConnected[i][j] == 1){

                    adj[i].push_back(j);
                    adj[j].push_back(i);

                }

            }
        }

        int count = 0;

        for(int i = 0; i<N; i++){
            if(visited[i] == false){

                DFS(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};