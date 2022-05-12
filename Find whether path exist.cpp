// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    bool solve(int i,int j,vector<vector<int>>&v,int x,int y){
       if(i<0 || i>=x || j<0 || j>=y || !v[i][j])return false;
       if(v[i][j]==2)return true;
       v[i][j]=0;
       return solve(i+1,j,v,x,y)+solve(i,j+1,v,x,y)+solve(i-1,j,v,x,y)+solve(i,j-1,v,x,y);
   }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
         int x=grid.size();
       int y=grid[0].size();
       for(int i=0;i<x;i++){
           for(int j=0;j<y;j++){
               if(grid[i][j]==1)
                   return solve(i,j,grid,x,y);
           }
       }
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends