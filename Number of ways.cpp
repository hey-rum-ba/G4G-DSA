// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int N){
        // code here
        long long ans[N+1] = {1};
        for(int i=1; i<=N; i++) {
        ans[i] = ans[i-1];
        if(i-4 >= 0) ans[i] += ans[i-4];
    }
    return ans[N];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends