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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        map<string,int> mp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    ds.unionbyrank(mp[accounts[i][j]],i);
                }else{
                    mp[accounts[i][j]]=i;
                }
            }
        }

        vector<vector<string>> ans(n);

        // vector<string> res(n);

        for(auto it:mp){
            string mail=it.first;
            int node=it.second;
            int parent=ds.find(node);
            ans[parent].push_back(mail);
        }

        vector<vector<string>> result;

        for(int i=0;i<ans.size();i++){
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(ans[i].begin(),ans[i].end());
            if(ans[i].size()!=0){
                for(auto it:ans[i]){
                    temp.push_back(it);
                }
                result.push_back(temp);
            }
        }

        // ans.push_back(res);




        return result;



        
    }
};