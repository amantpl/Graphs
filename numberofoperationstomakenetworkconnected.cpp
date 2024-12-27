
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
            size[parentu]+=size[parentv];
        }
    }

    int countcomponents(){
        set<int> st;
        for(int i=0;i<parent.size();i++){
            st.insert(find(parent[i]));
        }

        return st.size();
    }

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cables=0;
        sort(connections.begin(),connections.end());

        for(auto it:connections){
            int node1=it[0];
            int node2=it[1];

            if(ds.find(node1)==ds.find(node2)){
                cables++;
            }else{
                ds.unionbysize(node1,node2);
            }
        }
        
        
        
        int nu=ds.countcomponents();
        if(cables<nu-1){
            return -1;
        }else{
            return nu-1;
        }

        // return nu;
    }
};