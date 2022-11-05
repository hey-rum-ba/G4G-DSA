//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        int i=0,j=1;

        int ans=INT_MAX;

        int n=a.size();

        sort(a.begin(),a.end());

        if(n==1){

            return 0;

        }

        while(j<n && i<=j){

             if(a[j]-a[i]<=k){

                int x=(j-i)+1;

                ans=min(ans,n-x);

                j++;

            }

            else{

                i++;

            }

        }

        if(ans==INT_MAX){

            return 1;

        }

        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends