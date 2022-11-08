//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector< long long int> v;
        long long int res=0,x=0,count=0,b=0;
        for(long long int i=0;i<N;i++)
        {
          res=res^Arr[i];
        }
        while(!(res&(1<<count))){
            ++count;
        }
        b=b|(1<<count);
        for(long long int i=0;i<N;i++)
        {
         if(Arr[i]&b)
            x=x^res^Arr[i];
        }
        v.push_back(max(x,res^x));
        v.push_back(min(x,res^x));

        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends