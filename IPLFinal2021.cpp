// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
       int n=s.length();
       int i=0,maxx=0;
       stack<int>p;
       p.push(-1);
       while(i<n)
       {
           if(s[i]=='(')
           {
               p.push(i);
           }
           else
           {
               if(s[i]==')')
               {
                   if(!p.empty())
                   {
                       p.pop();
                       if(!p.empty())
                       {
                           maxx=max(maxx,i-p.top());
                       }
                       else
                       {
                           p.push(i);
                       }
                   }
               }
           }
           i++;
       }
       return maxx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends