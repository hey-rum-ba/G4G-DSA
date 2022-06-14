// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    int isCircle(int N, vector<string> A)
    {
        // code here
        unordered_map<char,int>m1,m2,m3; 
       for(int i=0;i<N;i++){
           m1[A[i][0]]++;
           m2[A[i][A[i].size()-1]]++;
           if(A[i][0]== A[i][A[i].size()-1]){
               m3[A[i][0]]++;
           }
       }
       if(m1.size()!=m2.size()) return 0;
       for(int i=0;i<N;i++){
           if(m1[A[i][0]]!=m2[A[i][0]]) return 0;
           else if(m3[A[i][0]]==m1[A[i][0]] && m3[A[i][0]]!=N){
               return 0;
           }
       }
       return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends