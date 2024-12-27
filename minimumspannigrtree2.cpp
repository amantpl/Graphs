//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
  public:
  
  DisjointSet(int n){
      rank.resize(n+1,0);
      parent.resize(n+1,0);
      size.resize(n+1,1);
      
      for(int i=0;i<n;i++){
          parent[i]=i;
      }
  }
  
  int find(int node){
      if(node==parent[node]){
          return node;
      }
      
      return parent[node]=find(parent[node]);
  }
  
  void unionbyrank(int u,int v){
      int parentu=find(u);
      int parentv=find(v);
      if(parentu==parentv) return ;
      if(rank[parentu]<rank[parentv]){
          parent[parentu]=parentv;
      }else if(rank[parentu]>rank[parentv]){
          parent[parentv]=parentu;
      }else{
          parent[parentv]=parentu;
          rank[parentu]++;
      }
  }
  
  void unionbysize(int u,int v){
      int parentu=find(u);
      int parentv=find(v);
      if(parentu==parentv) return ;
      if(size[parentu]<size[parentv]){
          parent[parentu]=parentv;
          size[parentv]+=size[parentu];
      }else{
          parent[parentv]=parentu;
          size[parentu]+=parentv;
      }
  }
};
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int node1=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,node1}});
            }
        }
        
        sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        
        int ans=0;
        
        for(auto it:edges){
            int wt=it.first;
            int node1=it.second.first;
            int node2=it.second.second;
            
            if(ds.find(node1)!=ds.find(node2)){
                ans+=wt;
                ds.unionbysize(node1,node2);
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends