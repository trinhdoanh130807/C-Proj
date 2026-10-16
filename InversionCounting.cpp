#include <bits/stdc++.h>
using namespace std;

vector<int> tem;
long long countInversion(vector<int> &a, int lo, int hi){
    if(hi - lo <= 1) {
        return 0; 
    }
    int mid = lo + (hi - lo) / 2;
    long long count = countInversion(a, lo, mid) + countInversion(a, mid, hi);
    int  i = lo, j = mid, k = lo;
    while ( i < mid && j < hi ){
        if(a[i] <= a[j]){
            tem[k ++] = a[i ++];
        }
        else{
            tem[k ++] = a[j ++];
            count += mid - i;
        }
    }
    while(i < mid){
        tem[k ++] = a[i ++];
    }
    while(j < hi){
        tem[k ++] = a[j ++];
    }
    for(int k = lo; k < hi; k ++){
        a[k] = tem[k];
    }
    return count;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin >> n;
    tem.resize(n);
    vector<int> a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    long long res = 1e9 + 7;
    cout << countInversion(a, 0, n) % res;
}