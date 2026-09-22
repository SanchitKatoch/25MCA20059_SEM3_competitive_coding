https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            adj[prerequisite].push_back(course);
            indeg[course]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        int count = 0;
        while(!q.empty()) {
            int currNode = q.front();
            q.pop();
            ans.push_back(currNode);
            count++;
            for(int adj_node : adj[currNode]) {
                indeg[adj_node]--;
                if(indeg[adj_node] == 0) {
                    q.push(adj_node);
                }
            }
        }
        if(count != numCourses) {
            return {};
        }
        return ans;
    }
};
