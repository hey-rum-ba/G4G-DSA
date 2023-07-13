//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    bool isFrequencyUnique(int n, int arr[])
    {
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        unordered_set<int> st;
        for (auto it : mp)
        {
            int x = it.second;
            if (st.count(x) > 0)
                return false;
            st.insert(x);
        }
        return true;
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        bool ans = ob.isFrequencyUnique(n, arr);
        if (ans)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
// } Driver Code Ends