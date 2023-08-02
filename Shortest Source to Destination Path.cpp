//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // code here
        if (A[0][0] == 0)
        {
            return -1;
        }
        if (X == 0 && Y == 0)
        {
            return 0;
        }
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        q.push({0, {0, 0}});
        visited[0][0] = true;

        int drow[] = {1, 0, -1, 0};
        int dcolumn[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            pair<int, pair<int, int>> curr = q.front();
            q.pop();

            int a = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if (x == X && y == Y)
            {
                return a;
            }
            for (int i = 0; i < 4; i++)
            {
                int newr = x + drow[i];
                int newc = y + dcolumn[i];

                if (newr >= 0 && newr < N && newc >= 0 && newc < M && A[newr][newc] == 1 && visited[newr][newc] == false)
                {
                    q.push({a + 1, {newr, newc}});
                    visited[newr][newc] = true;
                }
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends