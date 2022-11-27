//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    reverse(A.begin(), A.end());
	    reverse(B.begin(), B.end());
	    
	    int i = 0, carry = 0;
	    string res;
	    while(i < A.size() || i < B.size() || carry > 0) {
	        int sum = 0;
	        if(i < A.size()) sum += A[i] - '0';
	        if(i < B.size()) sum += B[i] - '0';
	        sum += carry;
	        int curr = sum % 2;
	        carry = sum / 2;
	        res.push_back(curr + '0');
	        i++;
	    }
	    
	    reverse(res.begin(), res.end());
        int count = 0;
        while(res[count] == '0') count++;
	    return res.substr(count);
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends