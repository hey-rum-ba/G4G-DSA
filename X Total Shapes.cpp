//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>&grid) {
       if (i<0 || j<0 || i>=n || j>=m) return;
       if (grid[i][j]=='O') return;
       grid[i][j] = 'O';
       dfs(i+1,j,n,m,grid);
       dfs(i-1,j,n,m,grid);
       dfs(i,j+1,n,m,grid);
       dfs(i,j-1,n,m,grid);
   }
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int ct = 0;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (grid[i][j]=='X'){
                    dfs(i,j,n, m,grid);
                    ct++;
                }
            }
        }    
        return ct;
       
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends