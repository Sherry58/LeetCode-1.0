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
    bool equationsPossible(vector<string>& equations) {
        parent.assign(26, 0);
        rank.assign(26, 0);

        for(int i=0; i<26; i++){
            parent[i]=i;
        }

        for(auto &s : equations){ //first process all == , doing both in a single loop will miss out the cases where != came first as it will skip if done that string or equation
            char x = s[0], symbol = s[1], y = s[3];

            if(symbol == '=') Union(x-'a', y-'a');
        }
        for(auto &s : equations){ //then process all !=
            char x = s[0], symbol = s[1], y = s[3];
            
            if(symbol == '!'){
                int x_parent = find(x-'a');
                int y_parent = find(y-'a');

                if(x_parent == y_parent) return false;
            }
        }
        return true;
    }
};