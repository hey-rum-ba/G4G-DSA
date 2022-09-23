//{ Driver Code Starts
//Initial template for C++
 
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int minLength(string s, int n) {
        // code here
        set<string> S ;
        S.insert( "12" ) ;
        S.insert( "21" ) ;
        S.insert( "34" ) ;
        S.insert( "43" ) ;
        S.insert( "56" ) ;
        S.insert( "65" ) ;
        S.insert( "78" ) ;
        S.insert( "87" ) ;
        S.insert( "09" ) ;
        S.insert( "90" ) ;
        
        stack<char> st;
        
        
        for(int i = 0 ; i < n ; i++)
        {
            if( st.empty() == true )
            {
                st.push( s[i] ) ;
                continue ;
            }
            
            
            string x ;
            char ch = st.top() ;
            
            x += ch ;
            
            x += s[i] ;
            
            if( S.find( x ) != S.end() )
            {
                st.pop() ;
            }
            else 
            {
                st.push( s[i] ) ;
            }
        }
        
        int cnt =  0;
        
        while( !st.empty() )
        {
            cnt++ ;
            st.pop() ;
        }
        
        return cnt ;
    } 
};


//{ Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends