//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int> ans(V,INT_MAX);
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        ans[0]=0;
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int dist=it.second;
            q.pop();
            
            for(auto it:adj[node]){
                int node1=it.first;
                int dist_from_node=it.second;
                if(dist+dist_from_node<ans[node1]){
                    ans[node1]=dist+dist_from_node;
                    q.push({node1,dist+dist_from_node});
                }
            }
            
        }
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends