class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> vis(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<times.size();i++){
            int node1=times[i][0];
            int node2=times[i][1];
            int time=times[i][2];

            adj[node1].push_back({node2,time});
        }

        queue<pair<int,int>> q;
        q.push({k,0});
        vis[k]=0;

        int ans=-1;
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int time=it.second;
            q.pop();

            ans=time;

            for(auto it1:adj[node]){
                int node1=it1.first;
                int time1=it1.second;
                int totaltime=time1+time;
                if(totaltime<vis[node1]){
                    vis[node1]=totaltime;
                    q.push({node1,time1+time});
                }

                
            }
        }

        sort(vis.begin(),vis.end());
        if(vis[vis.size()-2]==INT_MAX){
            return -1;
        }

        return vis[vis.size()-2];
    }
