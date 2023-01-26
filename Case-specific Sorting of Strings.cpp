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

// class Solution
// {
// public:
//     // Function to perform case-specific sorting of strings.
//     string caseSort(string str, int n)
//     {
//         // your code here
//         vector<char> up, dn;

//         for (int i = 0; i < str.size(); i++)

//         {

//             if (str[i] >= 'A' && str[i] <= 'Z')

//                 up.push_back(str[i]);

//             else

//                 dn.push_back(str[i]);
//         }

//         sort(up.begin(), up.end());

//         sort(dn.begin(), dn.end());

//         int x = 0, y = 0;

//         for (int i = 0; i < str.size(); i++)

//         {

//             if (str[i] >= 'A' && str[i] <= 'Z')

//             {

//                 str[i] = up[x];

//                 x++;
//             }

//             else

//             {

//                 str[i] = dn[y];

//                 y++;
//             }
//         }

//         return str;
//     }
// };

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