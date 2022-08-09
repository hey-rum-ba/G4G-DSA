//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long long int nineDivisors(long long int N){
       //Code Here
       bool seive[(long long)sqrt(N)+1];
       memset(seive,0,sizeof(seive));
       for(int i=2;i<=sqrt(N);i++){
           if(seive[i]==false){
               for(int j=2*i;j<=sqrt(N);j+=i){
                   seive[j]=true;
               }
           }
       }
       vector<long long int>prime;
       for(long long int i=2;i<=sqrt(N);i++){
           if(seive[i]==false)prime.push_back(i);
       }
       long long ans=0;
       int l=0,r=prime.size()-1;
       while(l<=r){
           int mid=(l+r)/2;
           long long x=(long long)pow(N,0.125);
           if(x>=prime[mid]){
               l=mid+1;
               ans=mid+1;
           }
           else r=mid-1;
       }
       for(int a=0;a<prime.size()-1;a++){
           int j=prime.size()-1,i=a,cur=0;
           while(i<=j){
               int mid=(i+j)/2;
               if(prime[a]*prime[mid]<=sqrt(N)){
                   cur=mid-a;
                   i=mid+1;
               }
               else j=mid-1;
           }
           ans+=cur;
       }
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
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.nineDivisors(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends