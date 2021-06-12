#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int heights[n];
    for(int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    sort(heights, heights + n);
    ll final = heights[0];
    ll sum = heights[0];
    for(int i = 1; i < n; ++i) {
        if (heights[i] > heights[i - 1] + k) {
            final = max(final, sum);
            sum = heights[i];
        } else {
            sum += heights[i];
        }
    }
    cout << max(final,sum) << "\n";
}
