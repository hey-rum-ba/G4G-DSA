// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    void dfs(int i,int j,int x,int y,vector<vector<int>>&matrix,int n,int m,int len,int &ans)
    {
        if(i>=n || j>=m || i<0 || j<0 || matrix[i][j]==0)
            return;
       
        if(i==x and y==j)
        {
            ans=max(ans,len);
            return;
        }
       
        matrix[i][j]=0;
        dfs(i+1,j,x,y,matrix,n,m,len+1,ans);
        dfs(i,j-1,x,y,matrix,n,m,len+1,ans);
        dfs(i-1,j,x,y,matrix,n,m,len+1,ans);
        dfs(i,j+1,x,y,matrix,n,m,len+1,ans);
       
        matrix[i][j]=1;
          
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        int ans=-1;
        int n=matrix.size(),m=matrix[0].size();
       
        dfs(xs,ys,xd,yd,matrix,n,m,0,ans);
        return ans;
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
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends