class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses, false);
        vector<int> indegree(numCourses, 0);

        for(auto &x : prerequisites){
            int v = x[0];
            int u = x[1];

            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int> que;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0) que.push(i);
        }

        int processed = 0;
        while(!que.empty()){
            int u = que.front();
            que.pop();

            processed++;

            for(auto &v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0) que.push(v);
            }
        }
        if(processed == numCourses) return true;
        else return false;

    }
};