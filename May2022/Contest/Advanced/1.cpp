#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

vector<int> V;
int ans = 0;

int avg() {
    int sum = 0;
    for (int x : V) sum += x;
    return sum / V.size();
}

int min() {
    int mn = 1000000000;
    for (int x : V) mn = min(mn, x);
    return mn;
}

int count(arr<int, 3> W, int h) {
    int cnt = 0;
    for (int i = W[0]; i <= W[1]; i++) {
        if (V[i] == h) cnt++;
    }
    return cnt;
}

double cost(arr<int, 3> W, int h) {
    double cnt = 0;
    for (int i = W[0]; i <= W[1]; i++) {
        if (V[i] == h) cnt++;
    }
    return (cnt == 0 ? 1000000000 : W[2] / cnt);
}

bool check(arr<int, 3> W, int h) {
    for (int i = W[0]; i <= W[1]; i++) {
        if (V[i] != h) return false;
    }
    return true;
}

void apply(arr<int, 3> W) {
    for (int i = W[0]; i <= W[1]; i++) {
        V[i]++;
    }
    ans += W[2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    V.resize(N, 0);
    int mx = 0;
    for (int i = 0; i < N; i++) {
        cin >> V[i];
        mx = max(mx, V[i]);
    }
    vector<arr<int, 3>> W(K);
    for (int i = 0; i < K; i++) {
        int a, b, c; cin >> a >> b >> c;
        W[i] = {a-1, b-1, c};
    }
    bool wrk = true;
    while (avg() != mx) {
        int mn = min();
        int pos = -1, mx = -1;
        for (int i = 0; i < K; i++) {
            if (check(W[i], mn)) {
                double tmp = count(W[i], mn);
                if (tmp > mx) {
                    pos = i;
                    mx = tmp;
                } else if (tmp == mx) {
                    if (cost(W[i], mn) < cost(W[pos], mn)) {
                        pos = i;
                        mx = tmp;
                    }
                }
            }
        }
        if (pos == -1) {
            wrk = false;
            break;
        } else {
            apply(W[pos]);
        }
        cout << ans << "\n";
        for (auto x : V) cout << x << " ";
        cout << "\n";
    }
    if (wrk) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }
}
