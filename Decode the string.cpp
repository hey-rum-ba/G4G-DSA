//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;
        
        for(auto i : s){
            if(isdigit(i) || i == '[' || isalpha(i)){
                st.push(i);
            }else if(i == ']'){
                string str;
                
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }
                
                st.pop();
                string number;
                while(!st.empty() && st.top() >= '0' && st.top() <='9'){
                    number = st.top() + number;
                    st.pop();
                }
                
                int no = stoi(number);
                string temp = str;
                while(no-- > 1){
                    str += temp;
                }
                
                for(auto i : str){
                    st.push(i);
                }
            }
        }
        
        string res;
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends