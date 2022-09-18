//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int Count(int L, int R){
		    // Code here
		    int countL = 0;

            vector<bool> v(L+1, true);
        
            v[0] = false;
        
            v[1] = false;
        
            
        
            for(int i=2; i<L; i++){
        
                if(v[i]){
        
                    countL++;
        
                    
        
                    for(int j=2*i; j<L; j=j+i){
        
                        v[j] = false;
        
                    }
        
                }
        
            }
            vector<bool> v2(R+1, true);
        
            
        
            v2[0] = false;
        
            v2[1] = false;
        
            int countR = 0;
        
            
        
            for(int i=2; i<=R; i++){
        
                if(v2[i]){
        
                    countR++;
        
                    
        
                    for(int j=2*i; j<=R; j=j+i){
        
                        v2[j] = false;
        
                    }
        
                }
        
            }
        
            
        
            int prime = countR - countL;
        
            int comp = R-L+1 - prime;
        
            int ans = comp - prime;
        
            return L ==1 ? ans-1 : ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends