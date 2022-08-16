//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> FactDigit(int N)
	{
	    // Code here
	    array<int, 10> fact;
	    fact[0] = 1;
	    fact[1] = 1;
	    for(int i=2; i<10; i++)
	        fact[i] = i*fact[i-1];
	    vector<int>ans;
	    int lstPos = 9;
	    while(N){
	        while(fact[lstPos] > N)
	            lstPos--;
	        ans.push_back(lstPos);
	        N-=fact[lstPos];
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends