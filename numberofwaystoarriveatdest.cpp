class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<pair<long long, long long>> adj[n];
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        ways[0] = 1;

        // Build the adjacency list
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Min-heap for Dijkstra's algorithm (distance, node)
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> q;
        q.push({0, 0});  // start at node 0 with distance 0
        dist[0] = 0;

        while (!q.empty()) {
            auto it = q.top();
            long long dis = it.first;
            int node = it.second;
            q.pop();

            // Process neighbors
            for (auto& it1 : adj[node]) {
                int adjnode = it1.first;
                long long edw = it1.second;

                // Relaxation step
                if (dis + edw < dist[adjnode]) {
                    dist[adjnode] = dis + edw;
                    q.push({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];  // reset the ways to reach adjnode
                } else if (dis + edw == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];  // Return the number of ways to reach the last node
    }
};
