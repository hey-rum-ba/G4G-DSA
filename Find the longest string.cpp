//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    static bool cmp(string a, string b)
    {
        if (a.length() != b.length())
        {
            return a.length() < b.length();
        }
        return a > b;
    }
    string longestString(vector<string> &words)
    {
        // code here
        unordered_map<string, int> mp;
        int n = words.size();

        for (int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }

        sort(words.begin(), words.end(), cmp);

        for (int i = n - 1; i >= 0; i--)
        {
            int l = words[i].length();
            int ye = true;
            string t = "";
            for (int k = 0; k < l; k++)
            {
                t += words[i][k];
                if (mp[t] == 0)
                {
                    ye = false;
                    break;
                }
            }
            if (ye)
            {
                return words[i];
            }
        }
        return "";
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends