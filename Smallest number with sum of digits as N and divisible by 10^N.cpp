//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	string convert_to_string(int n)
	{
	    string ans = "";
	    while(n > 9)
	    {
	        n -= 9;
	        ans += "9";
	    }
	    ans = to_string(n) + ans;
	    return ans;
	}
	string digitsNum(int N)
	{
	    // Code here.
	    string rest(N, '0');
	    string front = convert_to_string(N);
	    return  front + rest;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		string ans = ob.digitsNum(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends