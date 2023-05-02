//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxSweetness(vector<int> &sweetness, int N, int K)
    {
        // Write your code here.
        int left = 1;
        int right = accumulate(sweetness.begin(), sweetness.end(), 0);

        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            int pieces = 0;
            int currentSweetness = 0;

            for (int s : sweetness)
            {
                currentSweetness += s;
                if (currentSweetness >= mid)
                {
                    pieces++;
                    currentSweetness = 0;
                }
            }

            if (pieces > K)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++)
        {
            cin >> sweetness[i];
        }
        Solution ob;
        int res = ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends