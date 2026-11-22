#include <bits/stdc++.h>
using namespace std;
int n, K, Q;
vector<vector<int>> c;
vector<int> d;
vector<bool> visited;
int minPath;
int curPath;
int load;
int N;
int last;
vector<int> mout;
int m;
bool check(int i){
    if(!visited[i] && load < d[i]) return false;
    return !visited[i];
}
void Try(int k, int prevF, int curF){
    if(N == n){
        minPath = min(minPath, curPath + c[last][0]);
        return;
    }
    if(curPath + m + mout[last] >= minPath){
        return;
    }

    for(int i = 1; i <= n; i ++){
        if(!check(i)) continue;
        if(last == 0 && i <= prevF) continue;   

        int newF = (last == 0) ? i : curF;     
        visited[i] = true;
        curPath += c[last][i];
        load -= d[i];
        N ++;
        m -= mout[i];
        int tem = last;
        last = i;

        Try(k, prevF, newF);

        last = tem;
        visited[i] = false;
        curPath -= c[last][i];
        load += d[i];
        N --;
        m += mout[i];
    }

    if(k + 1 < K && last != 0){
        int tem = load;
        int tem2 = last;
        curPath += c[last][0];
        load = Q;
        last = 0;

        Try(k + 1, curF, 0);                 

        curPath -= c[tem2][0];
        load = tem;
        last = tem2;
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> n >> K >> Q;
    load = Q;
    N = 0;
    last = 0;
    c.resize(n + 1, vector<int> (n+1));
    d.resize(n + 1);
    mout.resize(n + 1);
    visited.resize(n + 1, false);
    curPath = 0;
    minPath = INT_MAX;
    for(int i = 1; i <= n; i ++){
        cin >> d[i];
    }
    for(int i = 0; i <= n; i ++){
        int tem = INT_MAX;
        for(int j = 0; j <= n; j ++){
            cin >> c[i][j];
            if(i != j){
                tem = min(tem, c[i][j]);
            }
        }
        m += tem;
        mout[i] = tem;
    }
    m -= mout[0];
    Try(0, 0, 0);
    cout << minPath;
    return 0;
}