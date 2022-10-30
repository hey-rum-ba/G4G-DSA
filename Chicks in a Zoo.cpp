//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    long newchick[n],chick=1;newchick[0]=1;

        for(int day=1;day<n;day++)    {
            if(day>=6) chick-=newchick[day-6];
            newchick[day]=chick*2;
            chick+=newchick[day];
        
        }    
        return chick;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends