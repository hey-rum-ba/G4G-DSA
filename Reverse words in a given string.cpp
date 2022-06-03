// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
         // code here 
         int left=0;
         int right=S.length()-1;
         string temp="";
         string ans="";
         int count=0; 
        
            while(left<=right)
            {
             
             if(S[left]!='.') 
             {
                 temp+=S[left];
             }
     
             
             else if(S[left]=='.')
             {
                 count =1;
                 if(ans!="")
                     ans=temp+"."+ans;
                 else
                     ans=temp;
                 temp="";
             }
                 left++;
            }
            
            if(temp!="" && count==1)
            ans=temp+"."+ans;
            else
            ans=temp;
               return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends