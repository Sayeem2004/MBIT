// Mohammad Khan
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    map<char, int> mp;
    int gcf = 0;
    for (char c : s) {
        mp[c]++;
        gcf = mp[c];
    }
    for (auto x : mp) {
        gcf = gcd(gcf, x.second);
    }
    if (gcf == 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 0; i < gcf; i++) {
        for (auto x : mp) {
            for (int q = 0; q < x.second/gcf; q++) {
                cout << x.first;
            }
        }
    }
    cout << "\n";
    return 0;
}
