class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> degree(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>());
        queue<int> q;
        for(int i=0; i<prerequisites.size(); i++) {
            degree[prerequisites[i].first]++;
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        int n=numCourses;
        for(int i=0;i<numCourses;i++) {
            if(degree[i]==0) {
                q.push(i);
                n--;
            }
        }
        while(!q.empty()) {
            int t=q.front();
            q.pop();
            for(int i=0;i<graph[t].size();i++) {
                if(--degree[graph[t][i]]==0) {
                    n--;
                    q.push(graph[t][i]);
                }
            }
        }
        if(n) {
            return false;
        } else {
            return true;
        }
    }
};
