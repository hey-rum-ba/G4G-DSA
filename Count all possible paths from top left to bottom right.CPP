//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   int mod = 1e9+7;

    long long int func(int i,int j,int m,int n,vector<vector<long long int>> &dp){

        if(i == m-1 and j == n-1) return 1;

        if(i >=m or j >=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=(func(i+1,j,m,n,dp)+func(i,j+1,m,n,dp))%mod;

    }

    long long int numberOfPaths(int m, int n){

        vector<vector<long long int>> dp(m,vector<long long int>(n,-1));

        return func(0,0,m,n,dp)%mod;

    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
