#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k, m, n; cin >> k >> m >> n;
    int ans = (k*10-n)%m == 0 ? (k*10-n)/m : (k*10-n)/m+1;
    cout << ans << "\n";
}
