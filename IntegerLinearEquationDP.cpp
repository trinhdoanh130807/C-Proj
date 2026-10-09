#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;
vector<int> Arr;
long long genRoot(int M, int n){
    for(int i = 0; i < n; i ++){
      for(int j = 0; j <= M - Arr[i]; j ++){
        dp[j + Arr[i]] = dp[j] + dp[j + Arr[i]];
      }
    }
    return dp[M];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M, n;
    cin >> n >> M;
    for(int i = 0; i < n; i ++){
      int tem;
      cin >> tem;
      Arr.push_back(tem);
      M -= tem;
    }
    if(M < 0){
      cout << 0;
      return 0;
    }
    dp.resize(M + 1, 0);
    dp[0] = 1;
    cout << genRoot(M, n);
}
