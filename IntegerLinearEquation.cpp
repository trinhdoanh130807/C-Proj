#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> Arr;
long long total = 0;
vector<int> Root;
void genRoot(int M, int index){
    if(index < 0 ){
        if(M == 0){
            total ++;
        }
        return;
    }
    for(int i = 0; i <= M; i ++){
        Root.push_back(i);
        genRoot(M - i * Arr[index], index - 1);
        Root.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, M;
    int tem;
    cin >> n >> M;
    for(int i = 0; i < n; i ++){
        cin >> tem;
        Arr.push_back(tem);
    }
    for(int i = 0; i < n; i ++){
        M -= Arr[i];
    }
    genRoot(M ,n - 1);
    cout << total << '\n';
}
