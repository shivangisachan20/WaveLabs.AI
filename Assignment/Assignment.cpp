Approach
Two vectors named low(represent the lowest time of insertion it can access except its parent) and tin(represent the time of insertion of current node).
We do DFS traversel on the graph. If adjacent node is not visited then call DFS traversal.
The DFS traversal will mark if as visited and set value of tin and low.
When the DFS call for the adjacent node is completed then node will check for the min val of low[node] and low[adjacent node] and then it will check if adjacent node can be visited after removing the edges(this can be checked by the condition if(tin[node] > low[adjacent node]) , if this condition is true then it means that the adjacent node cannot be visited after removal of the edges). Therefore this edge will be a part of answer.


// Code

class Solution
 {
    int timer = 1;
public:
void dfs(vector<int>adj[] , int node , int parent , vector<int>&tin , vector<int>&low , vector<int>&vis , vector<vector<int>>&ans)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto it:adj[node])
    {
        if(it == parent) continue;
        if(vis[it] == 0)
        {
            dfs(adj , it , node , tin , low , vis , ans);
            low[node] = min(low[node] , low[it]);
            if(tin[node] < low[it])
            ans.push_back({node , it});
        }
        else
        {
            low[node] = min(low[node] , low[it]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<int>adj[n];
        for(int i =  0;i<con.size();i++)
        {
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
        vector<vector<int>>ans;
        vector<int>vis(n , 0) , tin(n , 0) , low(n , 0);
        dfs(adj ,  0 , -1 , tin , low , vis , ans);
        return ans;
    }
};


// Complexity

// Time complexity: O(E + V)
