// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            
            int i = 0, count = 0;
            while(i < s.size()){
                string tmp;
                while(i < s.size() and s[i] != '.' and s[i] >= '0' and s[i] <= '9')tmp += s[i++]; //only accepting integer
                if(tmp.size() == 0 || tmp.size() > 3 || stoi(tmp) > 255 || stoi(tmp) < 0)return 0; // valid number checking
                if(tmp.size() >= 2 and tmp[0] == '0')return 0;
                if(s[i] == '.')count++;
                i++;
            }
            if(count < 3 || count > 3)return 0; //checking 32bit
            return 1;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends