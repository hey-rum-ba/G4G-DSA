//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxIntersections(vector<vector<int>> lines, int N)
    {
        // Code here
        map<int, int> mp;
        for (int i = 0; i < lines.size(); i++)
        {
            int a = lines[i][0], b = lines[i][1];
            mp[a]++;
            mp[b + 1]--;
        }
        int ans = INT_MIN, presum = 0;
        for (auto i : mp)
        {
            presum += i.second;
            ans = max(ans, presum);
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
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < N; i++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends