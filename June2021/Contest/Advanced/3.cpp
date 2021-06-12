// Maxwell Zen
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll k;

void solve() {
    cin >> n >> k;
    if (n<5) {
        cout << -1 << '\n';
        return;
    }
    if (n==5) {
        ll a = 5*k, b = 3*k;
        cout << a << ' ' << a << ' ' << b << ' ' << b << ' ' << b << '\n';
        return;
    }
    if (n%2==0) {
        ll ans[n];
        ans[0]=k*100+1000;
        ans[1]=k*99+998;
        ans[2]=ans[3]=k*10;
        for (int i = 4; i < n; i++) ans[i]=k*10-1;
        for (ll i : ans) cout << i << ' ';
        cout << '\n';
        return;
    }
    ll ans[n];
    for (int i = 2; i < n; i++) ans[i]=3*k;
    ans[0]=ans[1]=(ll)(3*(n-2)+1)*k/2;
    for (ll i : ans) cout << i << ' ';
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}
