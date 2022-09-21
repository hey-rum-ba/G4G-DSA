//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int K){
    	 string str = "";

        int n = S.length();

        for(int i=0;i<n;i++){

            if(S[i]!='-') str += S[i];

        }

        int m = str.length();

        string ans="";

        int count=0;

        for(int i=m-1;i>=0;i--){

            count++;

            char c = str[i];

            if(!isdigit(c) && islower(c)) c = toupper(c);

            ans += c;

            if(count==K && i!=0){

                ans+='-';

                count=0;

            }

        }

        reverse(ans.begin(),ans.end());

        return ans;
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string S;
	    cin>>S;
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends