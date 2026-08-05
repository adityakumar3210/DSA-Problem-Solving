class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        unordered_map<int, vector<int> > adj;

        for(int i=0; i<invocations.size(); i++) {

            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
        }

        vector<int> sub(n, 0);
        vector<int> vis(n, 0);

        queue<int> q;
        q.push(k);
        
        
        while(!q.empty()) {

            int fN = q.front(); q.pop();
            sub[fN] = 1;
            vis[fN] = 1;
            
            for(int neibh : adj[fN]) {
                if(vis[neibh] == 0)
                    q.push(neibh);
            }
         
        }

        vector<int> result;

        for(int i=0; i<n; i++) {

            if(sub[i] == 0) {

                for(int neibh : adj[i]) {

                    if(sub[neibh] == 1) {
                        result.resize(n);
                        iota(result.begin(), result.end(), 0);
                        return result;
                    }
                }
            }
               
        }


        for(int i=0; i<n; i++) {

            if(sub[i] == 0) 
               result.push_back(i);
        }

        return result;


    }
};