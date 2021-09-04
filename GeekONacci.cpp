#include <iostream>
using namespace std;

int geekonacci(int a,int b,int c,int n){
    if(n<=0) return 0;
   if (n==1) return a;
   if (n==2) return b;
   if (n==3) return c;
    return geekonacci(a,b,c,n-1)+geekonacci(a,b,c,n-2)+geekonacci(a,b,c,n-3);
}
class Solution{
    public:
    //Complete this function
    void printNos(int N)
    {
    static int i = 1;
     
    if (i <= N)
    {
        cout << i++ << " ";
        printNos(N);
    }
    }
};
int main() {
    int n;
    cin >> n;
    Solution mySolution;
    mySolution.printNos(n); 
	return 0;
}