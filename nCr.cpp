//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    const int mod = 1e9 + 7;
    int binaryexp(int x, int n)
    {
        if (n == 0)
            return 1;
        int temp = binaryexp(x, n / 2);
        if (n % 2 == 0)
            return (1LL * temp * temp) % mod;
        else
            return (((1LL * temp * temp) % mod) * x) % mod;
    }
    int nCr(int n, int r)
    {
        // code here
        if (r > n)
            return 0;
        if (r == n)
            return 1;
        long long ans = 1;
        for (int i = 1; i <= r; i++)
        {
            ans = (ans * 1LL * (i + (n - r))) % mod;
        }
        for (int i = 1; i <= r; i++)
        {
            int inv = binaryexp(i, mod - 2);
            ans = ((ans % mod) * (inv % mod)) % mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
}
// } Driver Code Ends