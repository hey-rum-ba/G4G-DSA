//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string> genIp(string &s) {
        // Your code here
        string t = s;
        int n = s.length();
        if(n<4||n>12) return {"-1"};
        vector<string>v;
        for(int  i=1;i<n-2;i++){
            string temp = t.substr(0,i);
            if(stoi(temp)>255||(temp[0]=='0'&&temp.length()>1)) break;
            t.insert(t.begin()+i,'.');
            string t1 = t;
            for(int j=i+2;j<n;j++){
                string temp2 = t.substr(i+1,j-(i+1));
                if(stoi(temp2)>255||(temp2[0]=='0'&&temp2.length()>1)) break;
                t.insert(t.begin()+j,'.');
                string t2=t;
                for(int k=j+2;k<n+2;k++){
                    string temp3 = t.substr(j+1,k-(j+1));
                    string temp4 = t.substr(k,n+2-(k));
                    if(stoi(temp3)>255||(temp3[0]=='0'&&temp3.length()>1)||stoi(temp4)>255||(temp4[0]=='0'&&temp4.length()>1)) continue;
                    
                    v.push_back(temp +'.'+temp2+'.'+temp3+'.'+temp4);
                    t = t2;
                }
                t =t1;
            }
            t = s;
        }
        if(v.size()==0) return {"-1"};
        return v;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends