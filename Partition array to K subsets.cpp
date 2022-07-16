//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool function(int a[],int n,int k,int sum,int i,vector<int>& v)
    {
        if(i==n) return 1; 
            
        unordered_set<int> st;
        for(int j=0;j<k;j++){
            if(st.insert(v[j]).second==0) continue;
            if(v[j]+a[i]>sum) continue;
    
            v[j]+=a[i];
            if( function(a,n,k,sum,i+1,v) ) return 1;
            v[j]-=a[i];
        }
        return 0;
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         sort(a,a+n,greater<int>());
         int sum=0;
         for(int i=0;i<n;i++) sum+=a[i];
         if(sum%k!=0) return 0;
         sum/=k;
         vector<int> v(k,0);
         return function(a,n,k,sum,0,v);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends