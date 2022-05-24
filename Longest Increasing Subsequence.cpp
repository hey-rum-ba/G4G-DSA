// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int dp(int a[],int n,int W,vector<vector<int>>& t){
       
       if(n==0) return 0;
       if(t[n][W]!=-1) return t[n][W];
       if(a[n-1]<W){
           return t[n][W]=max(1+dp(a,n-1,a[n-1],t),dp(a,n-1,W,t));
       }
       else return t[n][W]=dp(a,n-1,W,t);
       
   } 
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int x=INT_MIN;
       for(int i=0;i<n;i++){
           x=max(x,a[i]);
       }
       vector< vector<int>> t(n+2, vector<int> (x+2,-1));
      return dp(a,n,x+1,t);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends