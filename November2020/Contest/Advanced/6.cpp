#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int y, x; cin >> y >> x;
    int n, m; cin >> n >> m;
    string s; cin >> s;
    set<array<int,2>> v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.insert({a,b});
    }
    for (int i = 0; i < m; i++) {
        set<array<int,2>> v2;
        if (s[i] == 'W') {
            for (auto c : v) {
                v2.insert({c[0],max(1,c[1]-1)});
            }
        } else if (s[i] == 'E') {
            for (auto c : v) {
                v2.insert({c[0],min(y,c[1]+1)});
            }
        } else if (s[i] == 'N') {
            for (auto c : v) {
                v2.insert({max(1,c[0]-1),c[1]});
            }
        } else {
            for (auto c : v) {
                v2.insert({min(x,c[0]+1),c[1]});
            }
        }
        for (auto c : v2)
            v.insert({c[0],c[1]});
        cout << v.size() << "\n";
    }
}
