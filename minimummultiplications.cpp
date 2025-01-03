//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=1e5;
        vector<int> dist(mod,INT_MAX);
        queue<pair<int,int>> q;
        q.push({0,start});
        
        dist[start]=0;
        
        while(!q.empty()){
            int steps=q.front().first;
            int node=q.front().second;
            q.pop();
            
            if(node==end){
                return steps;
            }
            
            for(auto it:arr){
                int mul=(it*node)%mod;
                if(steps+1<dist[mul]){
                    dist[mul]=steps+1;
                    q.push({steps+1,mul});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends