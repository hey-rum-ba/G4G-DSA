//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long solve(int X, int Y, string S)
    {
        // code here
        long long ansFromPr = 0, ansFromRp = 0, p = 0, r = 0;

        for (auto &x : S)
        {
            if (x == 'p')
                p++;
            else if (x == 'r')
            {
                if (p)
                {
                    p--;
                    ansFromPr += X;
                }
                else
                    r++;
            }
            else
            {
                ansFromPr += (min(r, p) * Y);
                r = 0, p = 0;
            }
        }
        ansFromPr += (min(r, p) * Y);
        p = 0, r = 0;

        for (auto &x : S)
        {
            if (x == 'r')
                r++;
            else if (x == 'p')
            {
                if (r)
                {
                    r--;
                    ansFromRp += Y;
                }
                else
                    p++;
            }
            else
            {
                ansFromRp += (min(r, p) * X);
                r = 0, p = 0;
            }
        }
        ansFromRp += (min(r, p) * X);
        return max(ansFromPr, ansFromRp);
    }
};

//{ Driver Code Starts.
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int X, Y;
        cin >> X >> Y;
        string S;
        cin >> S;
        Solution obj;
        long long answer = obj.solve(X, Y, S);
        cout << answer << endl;
    }
}
// } Driver Code Ends