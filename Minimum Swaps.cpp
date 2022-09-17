//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumSwaps(int c[],int v[],int n,int k,int b,int T)
    {
            // code here
            int swap=0;

           int temp;

           int fast_sheep=0;

           int slow_Sheep=0;

           for(int i=n-1; i>=0; i--){

               temp = b-c[i];

               if(temp%v[i]==0)

               temp = temp/v[i];

               else

               temp = temp/v[i]+1;

               if(temp<=T){

                   k--;

                   fast_sheep++;

                   swap+=slow_Sheep;

               }

               else

               slow_Sheep++;

               if(k==0)

               return swap;

           }

          return -1;
    }
};

//{ Driver Code Starts.
int main(){
    int t=1,testcases=1;
    cin>>t;
    while(t>=testcases)
    {
        int n,k,b,T;
        cin>>n>>k>>b>>T;
        int c[n];
        int v[n];
        for(auto &j:c)
            cin>>j;
        for(auto &j:v)
            cin>>j;
        Solution s;
        int ans=s.minimumSwaps(c,v,n,k,b,T);
        cout<<ans<<endl;
        testcases++;
    }
    // TIME;
    return 0;
}
// } Driver Code Ends