//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        long long MOD =1e9+7;
        if(n <= 2){
            return n;
        }
        long long prev = 2;
        long long prev_prev = 1;
        for(int i = 3; i <=n; i++){
            long long curr = (prev + (i - 1)*(prev_prev))%(long long)MOD;
            prev_prev = prev;
            prev = curr;
        }
        return prev;
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends