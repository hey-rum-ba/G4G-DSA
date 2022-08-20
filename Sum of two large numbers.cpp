//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        int carry = 0;
        deque <char> sum;
        string res = "";
        while (!X.empty() || !Y.empty()) {
            int sumVal = (X.empty() ? '0': X.back()) + (Y.empty() ? '0': Y.back()) - 2 * '0' + carry;
            sum.push_front(sumVal % 10 + '0');
            carry = sumVal / 10;
            if (!X.empty())
                X.pop_back();
            if (!Y.empty())
                Y.pop_back();
        }
        if (carry)
            sum.push_front(carry + '0');
        while ((int) sum.size() > 1 && sum.front() == '0')
            sum.pop_front();
        for (auto &i: sum)
            res += i;
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends