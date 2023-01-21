// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        bitset<32>b1(a);
        bitset<32>b2(b);
        int a_count = b1.count();
        int b_count = b2.count();
        int diff = abs(a_count - b_count);
        if(diff == 0){
            return a;
        }
        else if(a_count > b_count){
            while(diff > 0){
                a = a & (a - 1);
                diff--;
            }
        }
        else{
            while(diff > 0){
                a = a | (a + 1);
                diff--;
            }
        }
        return a;
    }
};

// class Solution
// {
// public:
//     int minVal(int a, int b)
//     {

//         // code here

//         int sum = a;

//         int cnta = 0;

//         int cntb = 0;

//         for (int i = 0; i < 32; i++)

//         {

//             if ((1 << i) & a)

//             {

//                 cnta++;
//             }

//             if ((1 << i) & b)

//             {

//                 cntb++;
//             }
//         }

//         if (cnta == cntb)

//         {

//             return a;
//         }

//         else if (cnta > cntb)

//         {

//             int sum = a;

//             for (int i = 0; i < 32; i++)

//             {

//                 if ((1 << i) & a)

//                 {

//                     sum = sum ^ (1 << i);

//                     cnta--;

//                     if (cnta == cntb)

//                     {

//                         return sum;
//                     }
//                 }
//             }
//         }

//         else

//         {

//             int sum = a;

//             for (int i = 0; i < 32; i++)

//             {

//                 if (((1 << i) & a) == 0)

//                 {

//                     sum = sum | (1 << i);

//                     cnta++;

//                     if (cnta == cntb)

//                     {

//                         return sum;
//                     }
//                 }
//             }
//         }
//     }
// };

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends