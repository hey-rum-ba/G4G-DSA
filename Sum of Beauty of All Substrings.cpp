//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n = s.size();
        int res = 0;
        for(int i=0; i<n; i++){
            int hash[26] = {0};
            for(int j=i; j<n; j++){
                int mx = INT_MIN, mi = INT_MAX;
                hash[s[j]-'a']++;
                for(auto x : hash){
                    if(x){
                        mi = min(x, mi);
                        mx = max(x, mx);
                    }
                }
                res += mx - mi;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends