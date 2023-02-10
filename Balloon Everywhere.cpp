//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxInstance(string s)
    {
        string str = "balon";
        unordered_map<char, int> m;
        for (char &ch : s)
        {
            if (str.find(ch) < str.size())
            {
                ++m[ch];
            }
        }

        m['o'] /= 2;
        m['l'] /= 2;

        int ans = INT_MAX;
        for (auto &value : m)
        {
            ans = min(ans, value.second);
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.maxInstance(s) << endl;
    }
    return 0;
}
// } Driver Code Ends