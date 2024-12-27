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
        if(parent[node]==node){
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

    int count(){
        set<int> st;
        for(int i=0;i<parent.size();i++){
            st.insert(find(parent[i]));
        }
            return (int)st.size();
    }


};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxr=0;
        int maxc=0;
        for(int i=0;i<n;i++){
            int x=stones[i][0];
            int y=stones[i][1];
            maxr=max(maxr,x);
            maxc=max(maxc,y);
        }


        DisjointSet ds(maxr+maxc+2);

        for(int i=0;i<stones.size();i++){
            int node1=stones[i][0];
            int node2=stones[i][1]+maxr+1;
            if(ds.find(node1)!=ds.find(node2)){
                ds.unionbyrank(node1,node2);
            }
        }

        set<int> st;
        for(int i=0;i<stones.size();i++){
            int x=stones[i][0];
            int y=stones[i][1];
            st.insert(ds.find(x));
            st.insert(ds.find(y+maxr+1));
        }

        return n-st.size();
        
    }
};