class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
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

        vector<int> res;
        while(!que.empty()){
            int u = que.front();
            que.pop();

            res.push_back(u); // nodes are counted a sprocessed when they are popped from queue

            for(auto &v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0) que.push(v);
            }
        }
        if(res.size() == numCourses) return res; // all nodes processed
        else return {};

    }
};