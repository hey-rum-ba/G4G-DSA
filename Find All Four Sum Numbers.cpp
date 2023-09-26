//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int z = arr.size();
        for (int i = 0; i < z - 3; i++)
        {
            for (int j = i + 1; j < z - 2; j++)
            {
                int s = j + 1;
                int e = z - 1;
                while (s < e)
                {
                    int sum = arr[i] + arr[j] + arr[s] + arr[e];
                    if (sum == k)
                    {
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[s]);
                        v.push_back(arr[e]);
                        ans.push_back(v);
                        s++;
                        e--;

                        // remove duplicate
                        while (s < e && arr[s] == arr[s - 1])
                        {
                            s++;
                        }
                        while (s < e && arr[e] == arr[e + 1])
                        {
                            e--;
                        }
                    }
                    else if (sum < k)
                    {
                        s++;
                    }
                    else
                    {
                        e--;
                    }
                }
                // remove duplicate
                while (j < z - 2 && arr[j] == arr[j + 1])
                {
                    j++;
                }
            }
            // remove duplicate
            while (i < z - 3 && arr[i] == arr[i + 1])
            {
                i++;
            }
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends