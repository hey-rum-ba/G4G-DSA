// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int shortestPath( int x, int y){ 
        // code here 
     int mx=max(x,y);
     int mn=min(x,y);
     int ans=0,f=0;
     while(mx!=mn)
     {
         mx/=2;
         ans++;
         if(mx<mn)     
             { mn/=2; ans++ ;   }
        
     }
   
     return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends