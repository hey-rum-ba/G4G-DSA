//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod (int)(1e9 + 7)
class Solution
{
public:
    int sumOfNaturals(int n)
    {
        // code here
        return ((n * 1LL * (n + 1)) / 2) % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends