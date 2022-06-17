#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int N, K;
vector<vector<int>> A;
vector<int> T; // 0 = min, 1 = max, 2 = leaf
vector<int> L;

int solve(int n) {
    if (T[n] == 0) {
        int mx = 0, sm = 0;
        for (auto u : A[n]) {
            int tmp = solve(u);
            if (tmp == -1) sm++;
            else mx = max(mx, tmp);
        }
        cout << n << " " << max(mx, sm) << "\n";
        return max(mx, sm);
    } else if (T[n] == 1) {
        int mn = 1000000000;
        for (auto u : A[n]) {
            int tmp = solve(u);
            if (tmp == -1) mn = min(mn, -1);
            else mn = min(mn, tmp);
        }
        cout << n << " " << mn << "\n";
        return mn;
    } else {
        cout << n << " " << (L[n] == 0 ? -1 : K-L[n]+1) << "\n";
        return (L[n] == 0 ? -1 : K-L[n]+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    A.resize(N); T.resize(N); L.resize(N);
    for (int i = 1; i < N; i++) {
        int a; cin >> a;
        A[a-1].push_back(i);
    }
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (s == "max") {
            T[i] = 1;
        } else if (s == "min") {
            T[i] = 0;
        } else {
            T[i] = 2;
            L[i] = stoi(s);
        }
    }
    int pos = solve(0);
}
