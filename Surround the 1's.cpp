//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int Count(vector<vector<int>> &matrix)
    {
        // Code here
        int count = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++)
        {

            for (int j = 0; j < matrix[0].size(); j++)
            {
                int countz = 0;
                if (matrix[i][j] == 1)
                {
                    if (i > 0 and matrix[i - 1][j] == 0)
                    {
                        countz++;
                    }
                    if (i < rows - 1 and matrix[i + 1][j] == 0)
                    {
                        countz++;
                    }
                    if (j > 0 and matrix[i][j - 1] == 0)
                    {
                        countz++;
                    }
                    if (j < cols - 1 and matrix[i][j + 1] == 0)
                    {
                        countz++;
                    }
                    if (i > 0 and j < cols - 1 and matrix[i - 1][j + 1] == 0)
                    {
                        countz++;
                    }
                    if (i > 0 and j > 0 and matrix[i - 1][j - 1] == 0)
                    {
                        countz++;
                    }
                    if (i < rows - 1 and j < cols - 1 and matrix[i + 1][j + 1] == 0)
                    {
                        countz++;
                    }
                    if (i < rows - 1 and j > 0 and matrix[i + 1][j - 1] == 0)
                    {
                        countz++;
                    }
                }
                if (countz > 0 and countz % 2 == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution ob;
        int ans = ob.Count(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends