//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    public:
    
    DisjointSet(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        size.resize(n,1);
        
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
        if(parentu==parentv){
            return ;
        }
        
        if(rank[parentu]<rank[parentv]){
            parent[parentu]=parentv;
        }else if(rank[parentv]<rank[parentu]){
            parent[parentv]=parentu;
        }else{
            parent[parentv]=parentu;
            rank[parentu]++;
        }
    }
    
    void unionbysize(int u,int v){
        int parentu=find(u);
        int parentv=find(v);
        if(parentu==parentv){
            return ;
        }
        
        if(size[parentu]<size[parentv]){
            parent[parentu]=parentv;
            size[parentv]++;
        }else{
            parent[parentv]=parentu;
            size[parentu]++;
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int k=operators.size();
        
        DisjointSet ds(n*m);
        
        vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
        
        vector<vector<int>> mat(n,vector<int>(m,0));
        vector<int> ans;
        
        int count=0;
        
        for(int i=0;i<k;i++){
            int row=operators[i][0];
            int col=operators[i][1];
            
            if(mat[row][col]==1){
                ans.push_back(count);
                continue;
            }
            
            mat[row][col]=1;
            count++;
            
            int node1=row*m+col;

            for(auto it:directions){
                int x=row+it[0];
                int y=col+it[1];
                int node2=x*m+y;
                if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1){
                    if(ds.find(node1)!=ds.find(node2)){
                    ds.unionbyrank(node1,node2);
                    count--;
                    }
                }
                
            }
            
            ans.push_back(count);
        }
        

        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends