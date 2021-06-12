#include <bits/stdc++.h>
using namespace std;

long long get_dist(vector<int> a, vector<int> b){
    long long sum = 0;
    int n = a.size();
    unordered_map<int,int> pos;
    for(int i=0; i<n; i++){
        pos[a[i]] = i;
    }
    for(int i=0; i<n; i++){
        sum += abs(pos[b[i]] - i);
    }
    return sum;
}

vector<int> rotate(vector<int> a, int m){
    int n = a.size();
    vector<int> c(n);
    for(int i=n-m; i<n; i++){
        c[i-n+m] = a[i];
    }
    for(int i=0; i<n-m; i++){
        c[i+m]=a[i];
    }
    return c;
}

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int& i : a){
        cin >> i;
    }
    for(int& i : b){
        cin >> i;
    }

    long long ans = INT_MAX;
    for(int i=0; i<n; i++){
        ans = min(ans, get_dist(a, rotate(b, i)));
    }
    cout << ans;
}
