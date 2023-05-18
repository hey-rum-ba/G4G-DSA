//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &mat)
    {
        mat[row][col] = 0;

        if (row < mat.size() - 1 && mat[row + 1][col] == 1)
        {
            dfs(row + 1, col, mat);
        }
        if (row > 0 && mat[row - 1][col] == 1)
        {
            dfs(row - 1, col, mat);
        }
        if (col < mat[0].size() - 1 && mat[row][col + 1] == 1)
        {
            dfs(row, col + 1, mat);
        }
        if (col > 0 && mat[row][col - 1] == 1)
        {
            dfs(row, col - 1, mat);
        }
    }
    int closedIslands(vector<vector<int>> &matrix, int N, int M)
    {
        // Code here
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if ((i == N - 1 || i == 0) || (j == M - 1 || j == 0))
                {
                    if (matrix[i][j] == 1)
                    {
                        dfs(i, j, matrix);
                    }
                }
            }
        }
        int count = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (matrix[i][j] == 1)
                {
                    count++;
                    dfs(i, j, matrix);
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> matrix(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> matrix[i][j];

        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends