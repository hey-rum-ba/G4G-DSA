// { Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string isPart(int n) { 
        //complete the function here
        int partOfIt = n+2;
        for (int i=2; i < partOfIt; i++) 
            if ( partOfIt % i == 0) 
                return "No";
    
        return "Yes" ;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.isPart(n) << endl;
    
    }
    return 0; 
} 
  // } Driver Code Ends