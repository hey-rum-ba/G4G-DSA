//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string low="";
        string high="";
        for(int i=0;i<str.length();i++){
            if(str[i]>='A' && str[i]<='Z') high+=str[i];
            else low+=str[i];
        }
         
        sort(low.begin(),low.end());
        sort(high.begin(),high.end());
        string ans="";
        int k=0;
        int j=0;
        for(int i=0;i<str.length();i++){
            if(str[i]>='A' && str[i]<='Z') ans+=high[j++];
            else ans+=low[k++];
        }
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends