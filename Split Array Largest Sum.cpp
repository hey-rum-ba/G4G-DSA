//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool ispossible (int arr[] , int  n , int  k , int mid){
      int sum =0;
      int count =0;
      for (int  i=0; i<n; i++){
          if(arr[i] > mid ){
              return false;
          }
          sum = sum + arr[i];
          if (sum > mid ){
              sum = arr[i];
              count ++;
          }
          
          if (sum == mid ){
              sum =0;
              count ++;
          }
      }
      if (sum != 0){
          count ++;
      }
      if (count <= k)
          return true ;
     return false;
      
  }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int sum=0;
        for (int i =0; i<N; i++){
            sum = sum + arr[i];
            
        }
        int  hi= sum ;
        int  low  =1;
        int ans  =0;
        while (low <= hi){
            int  mid  = (low+hi)/2;
            if (ispossible(arr , N , K, mid)){
                ans  = mid ;
                hi = mid -1;
            }
            else {
                low= mid+1;
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends