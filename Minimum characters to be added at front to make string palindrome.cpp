//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        //Write your code here
        int n = str.size();
        int i = 0;
        int j = n-1;
        int temp_i = i;
        int temp_j = j;
        
        while(temp_i < temp_j){
            
            if(str[temp_i] == str[temp_j]){
                temp_i++;
                temp_j--;
            }
            else {
                temp_i = i;
                --j;
                temp_j = j;
            }
        }
        
        return n-j-1;
        
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends