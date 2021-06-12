// Alvin Li
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

string s;
int dp[(int)1e5+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    map<char, int> mndp;
    for(int i=0; i<26; i++)
        mndp['a'+i] = INT_MAX;

    dp[0] = 1;
    mndp[s[0]] = 0;

    for(int i=1; i<s.size(); i++){
        mndp[s[i]] = min(mndp[s[i]], dp[i-1]);

        dp[i] = 1 + mndp[s[i]];
    }

    for(int i=0; i<s.size(); i++)
        cerr << dp[i] << ' ';
    cerr << '\n';

    cout << dp[s.size()-1];
}
