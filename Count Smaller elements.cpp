//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<int> ans(n,0);
        vector<int> a;
        a.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
           int index = lower_bound(a.begin(),a.end(),arr[i])-a.begin();
           a.insert(a.begin()+index,arr[i]);
           ans[i]=index;
        }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends