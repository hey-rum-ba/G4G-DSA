//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = (int) 1e8;
    int solve(int n, vector<int> &dp) {
        if(n == 0) {
            return 1;
        }
        if(n < 0) {
            return 0;
        }
        if(dp[n] != -1) return dp[n];
        int pick1 = solve(n-1, dp) % mod;
        int pick2 = solve(n-2, dp) % mod;
        return dp[n] = (pick1 + pick2) % mod;
    }
    int tab(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            int pick1 = 0, pick2 = 0;
            if(i > 1) {
                pick2 = dp[i-2]%mod;
            }
            pick1 = dp[i-1]%mod;
            dp[i] = (pick1 + pick2) % mod;
        }
        return dp[n];
    }
    int spaceOptimisation(int n) {
        int prev1 = 0, prev2 = 0, curr = 0;
        prev1 = 1;
        for(int i = 1; i <= n; i++) {
            int pick1 = 0, pick2 = 0;
            if(i > 1) {
                pick2 = prev2%mod;
            }
            pick1 = prev1%mod;
            curr = (pick1 + pick2) % mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int fillingBucket(int N) {
        // code here
        return spaceOptimisation(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends