// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
         //Your code here
         int ans=0;
         int i = 0;
         bool neg = false;
         
           if(str[i] == 45){
               i = 1;
               neg = true;
             }
             
        for(; i<str.length(); i++){
             if(str[i]<48 || str[i]>57) 
                 return -1;
             else
                 ans= (ans*10) + (str[i]-48);
         }
         return neg ? ans * -1 : ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends