//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int numberOfSubsequences(string S, string W)
    {
        // code here

        int ans = 0;

        int j = 0;

        int i = 0;

        vector<pair<char, bool>> v;

        vector<int> a;

        for (int k = 0; k < S.length(); k++)

        {

            v.push_back({S[k], false});

            if (W[0] == S[k])

            {

                a.push_back(k);
            }
        }

        int start = 0;

        if (!a.empty())

        {

            i = a[0];
        }

        int m = 1;

        while (i < v.size() && !a.empty())

        {

            if (v[i].first == W[j] && v[i].second == false)

            {

                v[i].second = true;

                j++;

                if (j == W.length())

                {

                    ans++;

                    j = 0;

                    i = a[m] - 1;

                    m++;
                }
            }

            i++;
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
        string S, W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S, W) << endl;
    }
    return 0;
}

// } Driver Code Ends