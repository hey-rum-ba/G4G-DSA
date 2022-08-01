//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int cracked(int n, int k, vector<vector<int>> &dp)
    {
        if(k==0 || k==1)
            return dp[n][k] = 1;
        if(n==1)
            return dp[n][k] = k;
        
        if(dp[n][k]!=-1)
            return dp[n][k];
        int mini = INT_MAX;
        
        for(int i=1;i<=k;i++)
        {
            int temp = 1+max(cracked(n-1, i-1,dp), cracked(n, k-i, dp));
            mini = min(mini, temp);
        }
        return dp[n][k] = mini;

    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        return cracked(n,k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends