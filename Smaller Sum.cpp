//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<long long> smallerSum(int n, vector<int> &arr)
    {
        // Code here
        vector<vector<long long>> v;
        for (int i = 0; i < n; i++)
            v.push_back({i, (long long)arr[i]});

        sort(v.begin(), v.end(), [](const vector<long long> &a, const vector<long long> &b)
             { return a[1] < b[1]; });

        for (int i = 1; i < n; i++)
            v[i][1] += v[i - 1][1];
        vector<long long> res(n, 0);

        res[v[0][0]] = 0;
        int idx = -1;
        for (int i = 1; i < n; i++)
        {
            if (arr[v[i][0]] == arr[v[i - 1][0]])
                res[v[i][0]] = (idx == -1 ? 0 : v[idx][1]);
            else
            {
                idx = i - 1;
                res[v[i][0]] = v[idx][1];
            }
        }
        return res;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<long long> ans = ob.smallerSum(n, arr);
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                cout << ans[i] << " ";
            }
            else
            {
                cout << ans[i] << endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends