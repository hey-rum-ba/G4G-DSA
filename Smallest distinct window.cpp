// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    bool check(int mp[])
    {
        for(int i=0;i<256;i++)
            if(mp[i]==-1)
            return false;
        return true;
    }

    int findSubString(string str)
    {
        // Your code goes here
        int n=str.size();
        int mp[256]={0};
        for(int i=0;i<n;i++)mp[str[i]-'A']=-1;
        int j=0;
        int ans=INT_MAX;
        for (int i = 0; i < n; ++i)
        {
             mp[str[i]-'A']++;
             if(check(mp))
             {
                while(check(mp))
            {
                mp[str[j]-'A']--;
                j++;
            }
                ans=min(ans,i-j+2);

            }
            
        }
        
        return ans; 
         
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends