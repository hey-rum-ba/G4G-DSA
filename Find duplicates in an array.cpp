// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int>v; int flag = 0;
        sort(arr,arr+n);
        for(int i=0; i<n; i++) {
           if(arr[i] == arr[i+1]) {
               flag++;
               if(flag == 1) {
                   v.push_back(arr[i]);
               }
           }
           else {
               flag = 0;
           }
        }
        // return (v.size()>0)? v : -1;
        if(v.size() > 0) return v;
        return {-1};
       
       
    }
};

/*
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        set<int>seti;

        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
            seti.insert(arr[i]);
            i++;
            }
        }

        if(seti.empty())
        seti.insert(-1);
        vector<int>ans(seti.size());
        copy(seti.begin(),seti.end(),ans.begin());
        return ans;
    }
};
*/

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends