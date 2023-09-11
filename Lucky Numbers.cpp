// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool checkbyindex(int index,int start)
   {
       int count=0;
       if(index<start) return true;
       int i=1;
       
       while(start*i<index)
       {
           count++;
           i++;
       }
       if(start*i==index)
       {
           return false;
       }
       
       index=index-count;
       checkbyindex(index,start+1);
   }
public:
bool isLucky(int n) {
    // code here
    
    int index=n;
    bool flag =checkbyindex(n,2);
    return flag;
    
}
};
/*
class Solution{
public:
    bool isLucky(int n) {
        // code here
        int count=2;
        while(true){
            if(n%count == 0){
                return false;
            }
            if(count>n){
                return true;
            }
            n=(n-(n/count));
            count++;
        }
    }
};
*/

// { Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}  // } Driver Code Ends