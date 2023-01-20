//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int maxWeightCell(int N, vector<int> Edge)
    {
        // code here
        vector<int> adj[N];
        for (int i = 0; i < N; i++)
        {
            if (Edge[i] != -1)
            {
                adj[Edge[i]].push_back(i);
            }
        }
        int ans = 0;
        int temp = 0;
        int ans1 = 0;
        for (int i = 0; i < N; i++)
        {
            temp = 0;
            for (auto it : adj[i])
            {
                temp += it;
            }

            if (temp >= ans)
            {
                ans = temp;
                ans1 = i;
            }
        }
        return ans1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N;
        cin >> N;
        vector<int> Edge(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Edge[i];
        }
        Solution obj;
        int ans = obj.maxWeightCell(N, Edge);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends