//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int countPaths(int N)
    {
        // code here
        if (N == 1)
            return 0;
        long long ans = 0;
        for (int i = 2; i <= N; i++)
        {
            if (i % 2 == 0)
                ans = 3 * (ans + 1);
            else
                ans = 3 * (ans - 1);
            ans = ans % 1000000007;
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
        int N;
        cin >> N;

        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0;
}

// } Driver Code Ends