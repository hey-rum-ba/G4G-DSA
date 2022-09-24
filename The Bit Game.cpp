//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int swapBitGame(long long N){
        // code here 
        long long a=0; 

        long long b=0;

        while(N){

            if(N%2 && b>0)

                a^=b;

            if(N%2==0)

                b++;

            N/=2;

        }

        if(a)

            return 1;

        else

            return 2;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.swapBitGame(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends