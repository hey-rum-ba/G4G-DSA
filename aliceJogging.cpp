#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vpi vector<pair<int,int>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rrep(i,a,b) for (int i = a; i > b; i--)
#define repit(i,a,b) for (int i = a; i >= b; i--)
#define iter(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define CIN(n) int n;cin>>n;while(n--) 

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int maxWay(int n){
    if(n==1) return 1;
    int res ;
    res =maxWay(n-1)+1;
    return res;
    
}

int main()
{
    int n;
    cin>>n;
    cout<<maxWay(n)<<endl;
    return 0;
}