//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string stringMirror(string str)
    {
        // Code here
        string t = "";
        t.push_back(str[0]);
        for (int i = 1; i < str.size(); i++)
        {
            if (i != 1 && str[i - 1] == str[i])
            {
                t.push_back(str[i]);
            }
            else if (str[i - 1] > str[i])
            {
                t.push_back(str[i]);
            }
            else
            {
                break;
            }
        }
        string rev = t;
        reverse(rev.begin(), rev.end());
        return t + rev;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        string res = ob.stringMirror(str);
        cout << res << endl;
    }
}
// } Driver Code Ends