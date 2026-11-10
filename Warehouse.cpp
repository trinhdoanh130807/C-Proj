#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T, D;
    cin >> N >> T >> D;
    vector<int> a(N + 1), t(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> t[i];
    vector<vector<int>> dp(N + 1, vector<int>(T + 1, -1));

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        // Bắt đầu route tại trạm i
        if (t[i] <= T) dp[i][t[i]] = a[i];
        for (int j = t[i]; j <= T; j++) {
            for (int p = max(1, i - D); p < i; p++) {
                if (dp[p][j - t[i]] != -1) {
                    dp[i][j] = max(dp[i][j], dp[p][j - t[i]] + a[i]);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}