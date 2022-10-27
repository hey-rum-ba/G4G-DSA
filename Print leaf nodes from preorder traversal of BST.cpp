//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> ans;
    void solve(int arr[],int start, int end,int n)
    {
        if(start>end || start>=n)
            return;
        if(start==end)
        {
            ans.push_back(arr[start]);
            return;
        }
        int idx=end+1;
        for(int j=start+1;j<=end;j++)
        {
            if(arr[j]>arr[start])
            {
                idx=j;
                break;
            }
        }
        solve(arr,start+1,idx-1,n);
        solve(arr,idx,end,n);
            
    }
    vector<int> leafNodes(int arr[],int N) {
        // code here
        solve(arr,0,N-1,N);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends