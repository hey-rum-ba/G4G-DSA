//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string findLargest(int N, int S)
    {
        // code here
        if (N > 1 && S == 0)
        {
            return "-1";
        }
        if (S > 9 * N)
        {
            return "-1";
        }

        string str = "";

        while (N > 0)
        {
            if (S > 9)
            {
                S = S - 9;
                str = str + "9";
            }
            else
            {
                str = str + to_string(S);
                S = 0;
            }
            N--;
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, S;
        cin >> N >> S;

        Solution ob;
        cout << ob.findLargest(N, S) << "\n";
    }
    return 0;
}
// } Driver Code Ends