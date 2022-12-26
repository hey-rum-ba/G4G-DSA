//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<long long> all_pairs;
    void precompute()
    {
        // Code Here

        for (int i = 0; i < 63; i++)
        {
            for (int j = i + 1; j < 63; j++)
            {
                for (int k = j + 1; k < 63; k++)
                {
                    all_pairs.push_back(pow(2, i) + pow(2, j) + pow(2, k));
                }
            }
        }

        sort(all_pairs.begin(), all_pairs.end());
    }

    long long solve(long long l, long long r)
    {
        // Code Here
        int f_ind = lower_bound(all_pairs.begin(), all_pairs.end(), l) - all_pairs.begin();
        int s_ind = lower_bound(all_pairs.begin(), all_pairs.end(), r) - all_pairs.begin();
        if (all_pairs[s_ind] != r)
            s_ind = s_ind - 1;
        return s_ind - f_ind + 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        cout << ob.solve(l, r) << endl;
    }
    return 0;
}
// } Driver Code Ends