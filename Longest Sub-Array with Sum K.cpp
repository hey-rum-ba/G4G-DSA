//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int res=0,presum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++)
        {
            presum+=A[i];
            if(presum==K)
                res=i+1;
            if(mp.find(presum)==mp.end())
                mp.insert({presum,i});
            if(mp.find(presum-K)!=mp.end())
                res=max(res,i-mp[presum-K]);
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends