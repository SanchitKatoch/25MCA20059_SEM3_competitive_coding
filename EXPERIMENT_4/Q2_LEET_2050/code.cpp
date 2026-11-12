https://leetcode.com/problems/parallel-courses-iii/submissions/2194403466/
class Solution {
public:
    int dfs(int u, vector<vector<int>>& graph, vector<int>& time, vector<int>& memo) {
        if (memo[u]!=-1){
            return memo[u];
        } 
        int maxPrereqTime =0;
        for (int v:graph[u]) {
            maxPrereqTime =max(maxPrereqTime,dfs(v,graph,time,memo));
        }
        return memo[u]=time[u-1]+maxPrereqTime;
    }

    int minimumTime(int n,vector<vector<int>> &relations,vector<int> &time){
        vector<vector<int>> graph(n+1);
        for (auto& rel : relations) {
            int prev=rel[0];
            int next=rel[1];
            graph[next].push_back(prev);
        }
        vector<int> memo(n+1,-1);
        int totalTime = 0;
        for (int i =1;i<=n;++i) {
            totalTime =max(totalTime,dfs(i,graph,time,memo));
        }
        return totalTime;
    }
};
