//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    void solve(vector<int> adj[], vector<int> &vis, int start)
    {
        for (auto it : adj[start])
        {
            if (vis[it] == 0)
            {
                // cout<<it<<" ";
                vis[it] = 1;
                ans.push_back(it);
                solve(adj, vis, it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        ans.push_back(0);
        vis[0] = 1;
        solve(adj, vis, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends