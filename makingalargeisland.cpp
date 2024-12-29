
class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
  public:
  
  DisjointSet(int n){
      rank.resize(n,0);
      parent.resize(n,0);
      size.resize(n,1);
      
      for(int i=0;i<n;i++){
          parent[i]=i;
      }
  }
  
  int find(int node){
      if(node==parent[node]){
          return node;
      }
      
      parent[node]=find(parent[node]);

      return parent[node];
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
  
    void unionbysize(int u, int v) {
        int parentu = find(u);
        int parentv = find(v);
        if (parentu == parentv) return;
        if (size[parentu] < size[parentv]) {
            parent[parentu] = parentv;
            size[parentv] += size[parentu];  // Update size of parentv
        } else {
            parent[parentv] = parentu;
            size[parentu] += size[parentv];  // Update size of parentu
        }
    }

    int getsize(int node) {
        return size[find(node)];  // Return size of the component containing node
    }

};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
        int n=grid.size();

        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int row=i;
                    int col=j;
                    int node1=row*n+col;

                    for(auto it:directions){
                        int x=it[0]+row;
                        int y=it[1]+col;
                        int node2=x*n+y;
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
                            if(ds.find(node1)!=ds.find(node2)){
                                ds.unionbysize(node1,node2);
                            }
                        }
                    }
                }
            }
        }

        int ans=0;


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int totalsize=1;
                    int row=i;
                    int col=j;
                    int node=row*n+col;
                    set<int> uniqueParents;

                    for(auto it:directions){
                        int x=it[0]+row;
                        int y=it[1]+col;
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
                        int node1=x*n+y;
                        int parent = ds.find(node1);

                        if (uniqueParents.find(parent) == uniqueParents.end()) {
                            totalsize += ds.getsize(parent);
                            uniqueParents.insert(parent);
                        }
                        }

                    }
                    ans=max(ans,totalsize);

                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int row=i;
                    int col=j;
                    int node=row*n+col;
                    ans=max(ans,ds.getsize(node));
                }
            }
        }

        


        return ans;


    }
};