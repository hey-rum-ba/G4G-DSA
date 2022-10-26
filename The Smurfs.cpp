//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        unordered_map<char,int>mp;
        for(int i = 0 ; i < n ; i++){
            mp[a[i]]++;
        }
        
       if(mp['R']%2==0 and mp['B']%2==0 and mp['G']%2==0){
           return 2;
       }
       else if(mp['R']%2==1 and mp['B']%2==1 and mp['G']%2==1){
           return 2;
       }
       else{
           return 1;
       }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends