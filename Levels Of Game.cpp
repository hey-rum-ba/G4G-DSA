//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int maxLevel(int h,int m)
        {
            // code here
            int count =0;
            bool prev =false;
            while((h>0)&&(m>0)){  
                if(prev != true){
                h = h+3;
                m = m+2;
                count++;
                prev = true;
            }
            else if((h-5>0)&&(m-10>0)){
                h = h-5;
                m = m-10;
                prev = false;
                count++;
            }
            else if(h-20>0){
                h = h-20;
                m = m+5;
                prev =false;
                count++;
            }
            else{
                h =0;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends