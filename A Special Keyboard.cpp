// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        unordered_map<char,int> pos ;
        int n = S1.size() ;
        for(int i=0;i<n;i++)
        {
            pos[S1[i]] = i ;
        }
        
        int ans = 0 ;
        int prev = 0 ;
        
        for(char c : S2)
        {
            ans+=abs(prev-pos[c]) ;
            prev = pos[c] ;
        }
        
        return ans ; 
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends