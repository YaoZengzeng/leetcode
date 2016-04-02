class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n==1) {
            return {0};
        }
        vector<int> degree(n,0);
        vector<vector<int>> graph(n,vector<int>());
        queue<int> q;
        for(int i=0;i<edges.size();i++) {
            degree[edges[i].first]++;
            degree[edges[i].second]++;
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        for(int i=0;i<n;i++) {
            if(degree[i]==1){
                q.push(i);
            }
        }
        while(n>2) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                int t;
                t=q.front(),q.pop();
                n--;
                for(int j=0;j<graph[t].size();j++) {
                    degree[graph[t][j]]--;
                    if(degree[graph[t][j]]==1) {
                        q.push(graph[t][j]);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
