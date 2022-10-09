//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
    	bool isPrime(int n) {
            if(n < 2) {
                return false;
            }
            
            for(int i=2;i<=sqrt(n);i++) {
                if(n % i == 0) {
                    return false;
                }
            }
            
            return true;
        }
		int NthTerm(int N){
		    // Code here
		    int x = N;
        
            int i=0;
            while(true) {
                if(isPrime(x-i)) {
                    return N - (x-i);
                }
                
                if(isPrime(x+i)) {
                    return (x+i) - N;
                }
                
            i++;
		}
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
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends