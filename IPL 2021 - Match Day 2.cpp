//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        int pre = 0;
        set<pair<int,int>> s; vector<int> ans;
        int i;
        for(i=0; i<k; i++){
            s.insert({arr[i],i});
        }
        ans.push_back((*(--s.end())).first);
        s.erase({arr[pre],i-k});
        while(i < n){
            pre++;
            s.insert({arr[i],i}); i++;
        	ans.push_back((*(--s.end())).first);
            s.erase({arr[pre],i-k});
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends