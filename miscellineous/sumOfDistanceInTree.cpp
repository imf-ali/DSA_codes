class Solution {
public:
    void dfs1(vector<vector<int>> &graph,int root,int par,vector<int> &count,vector<int> &dis){
        for(auto it : graph[root]){
            if(it == par)   continue;
            dfs1(graph,it,root,count,dis);
            count[root] += count[it];
            dis[root] += dis[it] + count[it];
        }
    }

    void dfs2(vector<vector<int>> &graph,int root,int par,vector<int> &count,vector<int> &dis){
        for(auto it : graph[root]){
            if(it == par)   continue;
            dis[it] = dis[root] + count.size() - 2*count[it];
            dfs2(graph,it,root,count,dis);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> count(n,1);
        vector<int> dis(n,0);
        dfs1(graph,0,-1,count,dis);
        dfs2(graph,0,-1,count,dis);
        return dis;
    }
};
