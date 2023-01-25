//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int minOperation(string s)
    {
        // code here
        int n = s.length() - 1;
        int op = 0;
        bool appended = false;
        while (n >= 0)
        {
            int currlen = n + 1;
            if (!appended && currlen % 2 == 0 && s.substr(0, currlen / 2) == s.substr(currlen / 2, currlen / 2))
            {
                n -= (currlen / 2);
                appended = true;
            }
            else
            {
                n--;
            }
            op++;
        }
        return op;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends