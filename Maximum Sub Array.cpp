//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	     // code here
	     vector<int>v1,v2;
         v2.push_back(-1);
         int sum=0,Max=0;
          for(int i=0;i<n;i++){
              if(a[i]<0){
                  
                  if(sum>Max){
                  Max=sum;
                  v2=v1;
              }
                  sum=0;
                  v1.clear();
              }else{
                  sum+=a[i];
                  v1.push_back(a[i]);
              }
          }
          if(sum>Max)return v1;
          return v2;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends