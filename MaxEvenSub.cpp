#include <bits/stdc++.h>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    cin >> f[1];
    for(int i = 2; i <= n; i ++){
        int tem;
        cin >> tem;
        f[i] = f[i - 1] + tem;
    }
    int minEven = 0;
    int minOdd = INT_MAX;
    int res = INT_MIN;
    
    for(int i = 1; i <= n; i ++){
        if(f[i]%2 == 0){
            res = max(res, f[i] - minEven);
            minEven = min(minEven, f[i]);
        }
        else{
            if(minOdd != INT_MAX){
                res = max(res, f[i] - minOdd);
            }
            minOdd = min(minOdd, f[i]);
        }
    }
    cout << res;
}
// 0 4 -1 1 5 -3 -1 2 3 