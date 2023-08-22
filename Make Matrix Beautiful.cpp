//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find minimum number of operations that are required
    // to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> matrix, int n)
    {
        // code here
        int countr, countc, c = 0, r = 0;
        int maxir = INT_MIN;
        int maxic = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            countc = 0;
            countr = 0;
            for (int j = 0; j < n; j++)
            {
                countr += matrix[i][j];
                countc += matrix[j][i];
                r += matrix[i][j];
                c += matrix[j][i];
            }
            maxir = max(countr, maxir);
            maxic = max(countc, maxic);
        }
        if (maxir > maxic)
            ans = (maxir * n) - r;
        else
            ans = (maxic * n) - c;
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
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}

// } Driver Code Ends