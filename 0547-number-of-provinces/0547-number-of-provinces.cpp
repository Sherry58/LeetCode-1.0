class Solution {
public:
    void BFS(vector<vector<int>> &adj, int u, vector<bool>& visited){
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(auto &v : adj[u]){
                if(visited[v] == false){

                    BFS(adj, v, visited);
                }
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

                BFS(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};