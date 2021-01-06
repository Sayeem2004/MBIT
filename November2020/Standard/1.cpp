#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    cout << (((10*n-k)%m > 0) ? (10*n-k)/m+1 : (10*n-k)/m) << "\n";
}
