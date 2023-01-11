//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long int minIncrements(vector<int> arr, int N)
    {
        // Code here
        long long int i, j, count = 0, max_val = 0;
        map<int, long long> m1;

        sort(arr.begin(), arr.end());

        for (i = 0; i < N; i++)
        {
            if (max_val < arr[i])
            {
                max_val = arr[i];
            }
            else
            {
                max_val++;
                count += max_val - arr[i];
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends