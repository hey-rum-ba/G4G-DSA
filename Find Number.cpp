//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long findNumber(long long N)
    {
        // Code here
        long long ans = 0;
        vector<int> base5;
        while (N > 0)
        {
            N--, base5.push_back(N % 5);
            N /= 5;
        }
        for (int i = base5.size() - 1; i >= 0; i--)
        {
            ans = ans * 10 + 2 * base5[i] + 1;
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
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.findNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends