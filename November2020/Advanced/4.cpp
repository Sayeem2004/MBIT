#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    IOS;
    int n;
    cin >> n;
    int halvin[n];
    int wholevin[n];

    for(int i = 0; i < n; ++i) {
        cin >> halvin[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> wholevin[i];
    }
    int pairs = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(halvin[i] != halvin[j] && wholevin[i] != wholevin[j]) ++pairs;
        }
    }

    cout << pairs << "\n";
}
