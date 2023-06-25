//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col);

// } Driver Code Ends
class Solution
{
public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
    {
        // Your code here
        unordered_set<long long> set;
        vector<vector<int>> res;

        for (int i = 0; i < row; i++)
        {
            long long sum = 0;
            vector<int> temp;
            for (int j = 0; j < col; j++)
            {
                temp.push_back(M[i][j]);
                if (M[i][j] == 1)
                    sum += pow(2, j);
            }

            if (set.find(sum) == set.end())
            {
                set.insert(sum);
                res.push_back(temp);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int a[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        Solution ob;
        vector<vector<int>> vec = ob.uniqueRow(a, n, m);
        for (int i = 0; i < vec.size(); i++)
        {
            for (int x : vec[i])
            {
                cout << x << " ";
            }
            cout << "$";
        }
        cout << endl;
    }
}

// } Driver Code Ends