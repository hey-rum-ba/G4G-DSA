//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>&mat,vector<vector<int>>&dp,int i,int j){
        dp[i][j] = 1;
        for(auto it : dir){
            int x = i + it.first;
            int y = j + it.second;
            if(x<0 || y<0 || x>=mat.size() || y>=mat[0].size()|| mat[x][y] < mat[i][j] || dp[x][y]==1) continue;
            dfs(mat,dp,x,y);
        }
    }

    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
        vector<vector<int>>dp1(N,vector<int>(M,0));
        vector<vector<int>>dp2(N,vector<int>(M,0));
        for(int i=0;i<N;i++){
            dfs(mat,dp1,i,0);
            dfs(mat,dp2,i,M-1);
        }
        for(int i=0;i<M;i++){
            dfs(mat,dp1,0,i);
            dfs(mat,dp2,N-1,i);
        }   
        int ans = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(dp1[i][j] == 1 && dp2[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends