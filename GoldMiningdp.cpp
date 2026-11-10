#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n, L1, L2;
    cin >> n >> L1 >> L2 ;
    vector<int> f(n);
    for(int i = 0; i < n; i ++){
        cin >> f[i];
    }
    for(int i = 0; i < n; i ++){
        if(i - L2 < 0 && i - L1 >= 0) f[i] += *max_element(&f[0], &f[i - L1 + 1]);
        if(i - L2 >= 0) f[i] += *max_element(&f[i - L2], &f[i - L1 + 1]);
    }
    cout << *max_element(f.begin(), f.end());
}