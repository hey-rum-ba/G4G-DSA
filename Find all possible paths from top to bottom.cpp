
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>>res;
    
    void path(vector<vector<int>>&grid,int i,int j,vector<int>&dist)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size())
            return;
        if(i==grid.size()-1 && j==grid[i].size()-1)
            {
                res.push_back(dist);
                return;
            }
        dist.push_back(grid[i][j]);
        path(grid,i+1,j,dist);
        path(grid,i,j+1,dist);
        dist.pop_back();
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<int>dist;
        path(grid,0,0,dist);
        for(int i=0;i<res.size();i++)
        res[i].push_back(grid[n-1][m-1]);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends