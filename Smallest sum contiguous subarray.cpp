//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      int min_far = INT_MAX;
      int minVal = 0 ;
      
      for(int i =0 ; i < a.size(); i++){
          minVal += a[i];
          
          if(minVal < min_far)
            min_far = minVal;
        
          if(minVal > 0)
            minVal = 0 ;
      }
      
      return min_far;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends