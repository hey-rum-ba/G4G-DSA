#include <iostream>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;

        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        

        int ans = 0;
        for(int i=0;i<n;i++)if(arr[i]>x)
                ans++;

        cout << ans << "\n";
    }

    return 0;
}
