https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/submissions/2149577062/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &edges : roads) {
            adj[edges[0]].push_back({edges[1], edges[2]});
            adj[edges[1]].push_back({edges[0], edges[2]});
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &[v, w] : adj[u]) {
                ans = min(ans, w);
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
