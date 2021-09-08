#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    deque<int>deq;
	    deq.push_front(1);
	    for(int i =2;i<=n;i++) deq.push_back(i);
	    while(deq.size()>1){
           int k = deq.front();
           deq.pop_front();
           deq.pop_front();
           deq.push_back(k);
           }
        cout<<deq.front()<<endl;
	}
	return 0;
}