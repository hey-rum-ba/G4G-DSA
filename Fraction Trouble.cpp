// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
        vector<int> b(2,INT_MIN);
        long max =INT_MIN;
        for(int q =10000;q>=2;q--){
           int p = ((q*n)-1)/d;
           long v = ((long)p*(long)10000000)/(long)(q);
           if(max<v && p<=q) {
               max=v;
               b[0]=p;
               b[1]=q;
               
           }
               
       } 
       return b;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends