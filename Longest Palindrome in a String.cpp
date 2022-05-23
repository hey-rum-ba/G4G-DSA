// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n=s.size();
        bool dp[n][n];
        int i=0,j=0;
       for(int gap=0;gap<n;gap++)
       {
           for(i=0,j=gap;j<n;j++,i++)
           {
               if(gap==0)
               {
                   dp[i][j]=true;
               }
               else if(gap==1)
               {
                   if(s[i]==s[j])
                   {
                       dp[i][j]=true;
                   }
                   else
                    dp[i][j]=false;
               }
               else
               {
                   if(s[i]==s[j] && dp[i+1][j-1]==true)
                    dp[i][j]=true;
                   else
                    dp[i][j]=false;
               }
           }
       }
       int strt=0,end=0,maxlen=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(dp[i][j]==true)
               {
                   if(j-i+1 > maxlen)
                   {
                       strt=i;
                       end=j;
                       maxlen=j-i+1;
                   }
               }
           }
       }
       string ans;
       for(int i=strt;i<=end;i++)
        ans+=s[i];
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends