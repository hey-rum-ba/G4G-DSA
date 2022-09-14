//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long long numberOfSubsequences(int N, long long A[]){
        // code here 
        int count=0;

       long long mod=1000000007;

       int res=1;

       for(long long i=0;i<N;i++)

       {

           if((A[i] & (A[i]-1))==0)// to check if it's a power of two or not

           count++;

       }

       while(count--)

       {

           res=((res%mod)*2)%mod;

       }

       return  res-1;
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
        long long A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    }
    return 0; 
} 
// } Driver Code Ends