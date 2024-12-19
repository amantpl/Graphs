class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(ans.size()==numCourses){
            return true;
        }

        return false;
    }
};