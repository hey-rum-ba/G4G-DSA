//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs(vector<vector<int>> &M, int i, int j,int &count)
    {
        int n = M.size(), m = M[0].size();
        if (i >= n || j >= m || i < 0 || j < 0 || M[i][j] == 0)
            return;
        
        M[i][j] = 0;
        count++;
        dfs(M, i, j + 1,count);
        dfs(M, i + 1, j,count);
        dfs(M, i + 1, j + 1,count);
        dfs(M, i - 1, j,count);
        dfs(M, i, j - 1,count);
        dfs(M, i - 1, j - 1,count);
        dfs(M, i - 1, j + 1,count);
        dfs(M, i + 1, j - 1,count);
    }
//Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++)
            {
                int count=0;
                if(grid[i][j]==1)
                       dfs(grid, i, j,count);
                ans=max(ans,count);
            }
          
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends