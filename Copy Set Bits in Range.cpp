//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
         int arr1[32]={0};

        for(int i=0;i<32;i++)

        {

            if(x&1==1)

            arr1[i]=1;

            else

            arr1[i]=0;

            x=x>>1;

        }

        int arr2[32]={0};

         for(int i=0;i<32;i++)

        {

            if(y==0)

            break;

            if(y&1)

            arr2[i]=1;

            else

            arr2[i]=0;

            y=y>>1;

        }

        for(int i=l-1;i<r;i++)

        {

            if(arr2[i]==1)

            arr1[i]=arr2[i];

        }

        

        int temp=0;

        for(int i=0;i<32;i++)

        {

            temp+=pow(2,i)*arr1[i];

        }

       

        return temp;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends