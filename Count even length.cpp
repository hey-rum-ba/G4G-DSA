//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int MOD = 1e9 + 7;

    long long binpow(long long a, long long b)
    {

        a %= MOD;

        long long res = 1;

        while (b > 0)
        {

            if (b & 1)

                res = res * a % MOD;

            a = a * a % MOD;

            b >>= 1;
        }

        return res;
    }

    long long int mul(long long int x, long long int y)

    {

        return (x * 1ll * y) % MOD;
    }

    long long int modInv(long long int a)
    {

        return binpow(a, MOD - 2) % MOD;
    }

    long long int divide(long long int x, long long int y)

    {

        return mul(x, binpow(y, MOD - 2));
    }

    int compute_value(int n)

    {

        // Code here

        long long int fact1 = 1;

        for (long long int i = 1; i <= 1ll * 2 * n; ++i)

        {

            fact1 = (fact1 * i) % MOD;
        }

        long long int fact2 = 1;

        for (long long int i = 1; i <= n; ++i)

        {

            fact2 = (fact2 * i) % MOD;
        }

        long long res1 = divide(fact1, fact2);

        res1 = divide(res1, fact2);

        return res1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.compute_value(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends