#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    vector<long long> W(N + 1, 0), R(N + 1, 0);
    R[0] = 1;                  
    R[1] = 1;                  

    for (int i = 1; i <= N; i++) {
        for (int k = K1; k <= min(K2, i); k++)
            W[i] += R[i - k];  
        if (i >= 2) R[i] = W[i - 1];
    }

    cout << W[N] + R[N];
    return 0;
}