// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string s1,s2;
        for(int i=0;i<n;)
        {
            
            s1=s1+to_string(arr[i]);
            i=i+2;
            
        }
        for(int i=1;i<n;)
        {
            
            s2=s2+to_string(arr[i]);
            i=i+2;
            
        }
        if(s1.length()!=s2.length())
         {
             reverse(s2.begin(),s2.end());
             s2=s2+to_string(0);
              reverse(s2.begin(),s2.end());
         }

        int i=s1.length()-1;
        string ans;
        int sum=0;
        int carry=0;
        while(i>=0)
        {
            int a=s1[i]-'0';
            int b=s2[i]-'0';
            sum=a+b+carry;
            carry=sum/10;
            ans=ans+to_string(sum%10);
            i--;   
        }
        
       if(carry)
       ans=ans+to_string(1);
       
       reverse(ans.begin(),ans.end());
       while(ans[0]=='0')
       {
           ans.erase(ans.begin());
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends