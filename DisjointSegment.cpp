#include <bits/stdc++.h>
using namespace std;
bool comparator(const pair<int, int> &x, const pair<int, int> &y){
    return x.second < y.second;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for(int i = 0; i < n; i ++){
        cin >> ab[i].first >> ab[i].second;
    }    
    sort(ab.begin(), ab.end(), comparator);
    int last = INT_MIN;
    int cnt = 0;
    for(auto &i : ab){
        if(i.first > last){
            cnt ++; 
            last = i.second;
        }
    }
    cout << cnt;
}