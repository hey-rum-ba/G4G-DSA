//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long solve(long long x)
    {
        long long sum = (x * 1ll * pow(2, x - 1) * 1ll) + 1;
        return sum;
    }
    long long countBits(long long N)
    {
        // code here
        long long sum = 0;
        while (N)
        {
            long long x = log2(N);
            if (sum != 0)
                sum += N;
            sum += solve(x);
            N = N - pow(2, x);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        long long N;
        scanf("%lld", &N);

        Solution obj;
        long long res = obj.countBits(N);

        cout << res << endl;
    }
}

// } Driver Code Ends