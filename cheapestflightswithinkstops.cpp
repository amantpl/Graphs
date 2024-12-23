class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0;i<flights.size();i++){
            int node1=flights[i][0];
            int node2=flights[i][1];
            int price=flights[i][2];

            adj[node1].push_back({node2,price});
        }

        vector<int> vis(n,INT_MAX);

        queue<pair<pair<int,int>,int>> q;
        // source , distance, no of curr steps
        q.push({{src,0},0});
        int ans=INT_MAX;
        vis[src]=0;

        while(!q.empty()){
            auto it=q.front();
            int node=it.first.first;
            int price=it.first.second;
            int steps=it.second;
            q.pop();

            if(node==dst){
                ans=min(ans,price);
            }

            if(steps<=k){
            for(auto it1:adj[node]){
                int node1=it1.first;
                int price1=it1.second;
                int totalprice=price1+price;
                if(totalprice<vis[node1]){
                    vis[node1]=totalprice;
                    q.push({{node1,price+price1},steps+1});
                }
            }
            }
        }

        
        if(ans==INT_MAX){
            return -1;
        }
        return ans;

        
    }
};