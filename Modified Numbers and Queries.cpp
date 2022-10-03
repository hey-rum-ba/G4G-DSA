//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
      int prime(int n ){
          int x=0;
          set<int>s;
          if(n==1||n==2||n==3){
              return n ;
          }
          for(int i=2;i<=n;i++){
              while(n%i==0){
                  s.insert(i);
                  n/=i;
              }
          }
          vector<int>v(s.begin(),s.end());
          for(int i=0;i<v.size();i++){
              x+=v[i];
          }
          return x;
      }
    int sumOfAll(int l, int r){
          // code here
          int sum=0;
          for(int i=l;i<=r;i++){
              sum+=prime(i);
          }
          return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;
        Solution ob;
        cout<<ob.sumOfAll(l,r)<<endl;
    }
    return 0;
}

// } Driver Code Ends