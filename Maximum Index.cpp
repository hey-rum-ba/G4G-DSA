//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxIndexDiff(int arr[], int n)
    {
        // code here
        int maxDiff;

        int RMax[n];
        int LMin[n];

        LMin[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            LMin[i] = min(LMin[i - 1], arr[i]);
        }

        RMax[n - 1] = arr[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            RMax[j] = max(RMax[j + 1], arr[j]);
        }

        int i = 0;
        int j = 0;

        maxDiff = 0;

        while (i < n && j < n)
        {
            if (LMin[i] <= RMax[j])
            {
                int diff = j - i;
                maxDiff = max(maxDiff, diff);
                j++;
            }
            else
            {
                i++;
            }
        }

        return maxDiff;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends