//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        // code here
        vector<vector<string>> ans;
        
        for(int i=0; i<details.size(); i++){
            if(details[i][0] != "-"){ 
                set<string> s;
                vector<string> v;
                for(int j=1; j<details[i].size(); j++){
                    s.insert(details[i][j]);
                }
                
                for(int k=i+1; k<details.size(); k++){
                    if(details[k][0] != "-"){
                        for(int j=1; j<details[k].size(); j++){
                            auto isPresent = s.find(details[k][j]);
                            if(isPresent != s.end()){    
                                details[k][0] = "-";
                                for(int j=1; j<details[k].size(); j++){
                                    s.insert(details[k][j]);
                                }
                            }
                            
                        }
                    }
                }
                v.push_back(details[i][0]);
                for(auto it=s.begin(); it != s.end(); it++) v.push_back(*it);
                ans.push_back(v);
            }
        }
        sort(ans.rbegin(), ans.rend());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends