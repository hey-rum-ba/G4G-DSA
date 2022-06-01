// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    void seive(int n, vector<int> &primeFactors) {
        
        bool primes[n+1];
        memset(primes, 1, n+1);
        
        for (int i=2; i*i<=n; i++) {
            
            if (primes[i]) {
                for (int j = i*i; j<=n; j+=i)  
                    primes[j] = false;
            }
        }
        
        for (int i=2; i<=n; i++) {
            if (primes[i] && n%i == 0) {
                primeFactors.push_back(i);
            }
        }
    }
    int smithNum(int n) {
        // code here
        int sum = 0;
        vector<int> p;
        sort(p.begin(), p.end());
       
        seive(n, p);
        int n1 = n;
        
        
        int i=0;
        while (n > 1) {
           
            if (n1 == p[i]) break;
            
            if (n%p[i] == 0) {
                int p1 = p[i];
                n /= p1;
                
                while (p1 > 0) {
                    sum += p1%10;    
                    p1 = p1/10; 
                }
                
            } else {
                i++;
            }
        }

        int sum2 = 0;
        int n2 = n1;
        while (n1 > 0) {
            sum2 += n1%10;
            n1 = n1/10;
        }

        if (sum == sum2)
            return 1;
        
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}  // } Driver Code Ends