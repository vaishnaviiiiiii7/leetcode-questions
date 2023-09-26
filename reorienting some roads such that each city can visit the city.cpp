class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:connections){
            adj[x[0]].push_back({x[1],1});
            adj[x[1]].push_back({x[0],0});
        }
        queue<int>qu;
        vector<int>vis(n,-1);
        qu.push(0);
        vis[0]=0;
        int ans=0;
        while(!qu.empty()){
            int cur=qu.front();
            qu.pop();
            for(auto x: adj[cur]){
                if(vis[x.first]==-1){
                    vis[x.first]=vis[cur]+1;
                    ans+=x.second;
                    qu.push(x.first);
                }
            }
        }
        return ans;
        
    }
};
