// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     int k=0;
     if(x.length()==0)
     return 0;
     for(int i=0;i<s.length();i++)
     {  
        while(s[i+k]==x[k]&&k<x.length())
        {
             k++;
             if(k==x.length())
             return i;
        }
        if(s[i+k]!=x[k])
        {
            k=0;
        }
       
     }
     return -1;
}