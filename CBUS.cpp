#include <bits/stdc++.h>
using namespace std;
int n, k; 
int minPath = INT_MAX;
int curPath = 0;
vector<int> x;
vector<vector<int>> c;
int load = 0;
int sum;
vector<bool> visited;
vector<int> mout;
bool check(int i){
    if(visited[i]){
        return false;
    }
    if(i <= n){
        if(load >= k){
            return false;
        }
    }
    else{
        if(!visited[i - n]){
            return false;
        }
    }
    return true;
}
void Try (int index){
    for(int i = 1; i < 2 * n + 1; i ++){
        if(check(i)){
            x[index] = i;
            curPath += c[x[index - 1]][i];
            visited[i] = true;
            sum = sum - mout[i];
        if(i <= n){
            load ++;
        }
        else{
            load --;
        }
        if(index == 2 * n){
            minPath = min(minPath, curPath + c[i][0]);
        }
        else{
            if(sum + curPath + mout[i] < minPath){
                Try(index + 1);
            }
        }
        if(i <= n){
            load --;
        }
        else{
            load ++;
        }
        visited[i] = false;
        sum += mout[i];
        curPath -= c[x[index - 1]][i];
        }
        else{
            continue;
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    mout.resize(2 * n + 1, INT_MAX);
    c.resize((2 * n + 1), vector<int> (2 * n + 1));
    for(int i = 0; i < 2 * n + 1; i ++){
        for(int j = 0; j < 2 * n + 1; j ++){
            cin >> c[i][j];
            if(i != j){
                mout[i] = min(mout[i], c[i][j]);
            }
        }
    }
    sum = 0;
    for(int i = 1; i < 2 * n + 1; i ++){
        sum += mout[i];
    }
    x.resize(2 * n + 1, 0);
    visited.resize(2 * n + 1, false);
    Try(1);
    cout << minPath; 
    
}