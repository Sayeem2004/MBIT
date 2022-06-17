#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, Q; cin >> N >> Q;
    vector<int> P(N), S(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<vector<arr<int, 3>>> V(N);
    V[N-1].push_back({0, P[N-1], S[N-1]});
    for (int i = N-2; i >= 0; i--) {
        V[i].push_back({0, P[i], S[i]});
        int pos = V[i].size()-1;
        for (int q = 0; q < V[i+1].size(); q++) {
            if (V[i+1][q][2] >= V[i][pos][2]) {
                continue;
            } else {
                int dist = 
            }
        }
    }
}
