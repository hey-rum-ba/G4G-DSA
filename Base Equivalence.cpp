//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int log_ab(int a, int b) {
                float ans = (float)log2(a) / log2(b);
                return ans + 1;
            }
          
    string baseEquiv(int n, int m){
        // code here
        int lo = 2, hi = 32;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int len = log_ab(n, mid);
            // cout << mid << " " << len << endl;
            if (len == m)
                return "Yes";
            if (len > m)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends