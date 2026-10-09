#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> Arr;
long long total = 0;
vector<int> Root;
vector<int> gcdArr;
void genRoot(int M, int index){
    if(index == 0){
        if(M % Arr[index] != 0){
            return;
        }
        else{
            total ++;
        }
        return;
    }
    if(M % gcdArr[index] != 0){
        return;
    }
    if(M == 0) {
        total ++;
        return;
    }
    for(int i = 0; i * Arr[index] <= M; i ++){
        Root.push_back(i);
        genRoot(M - i * Arr[index], index - 1);
        Root.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M;
    int tem;
    cin >> n >> M;
    for(int i = 0; i < n; i ++){
        cin >> tem;
        Arr.push_back(tem);
    }
    sort(Arr.begin(), Arr.end());
    for(int i = 0; i < n; i ++){
        M -= Arr[i];
    }
    gcdArr.push_back(Arr[0]);
    for(int i = 0; i < n - 1; i ++){
        gcdArr.push_back(gcd(gcdArr[i], Arr[i + 1]));
    }
    genRoot(M ,n - 1);
    cout << total << '\n';
}
