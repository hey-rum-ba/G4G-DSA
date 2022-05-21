// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
        //code here
        vector<int> ans(N, -1), v(N);
        v[N - 1] = Arr[N - 1];
        for (int i = N - 2; i >= 0; i--)
        {
            auto it = upper_bound(v.begin(), v.end(), Arr[i] - 1) - v.begin() - 1;
            ans[i] = (it <= i ? -1 : it);
            v[i] = min(v[i + 1], Arr[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends