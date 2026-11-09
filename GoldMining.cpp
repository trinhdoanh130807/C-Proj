#include <bits/stdc++.h>
using namespace std;
bool comparator(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n, L1, L2;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comparator)> pqiv(comparator);
    cin >> n >> L1 >> L2;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i ++){
        if(i - L1 >= 0){
            pqiv.push({i - L1, arr[i - L1]});
            while(i - pqiv.top().first > L2){
                pqiv.pop();
            }
            arr[i] += pqiv.top().second;
        }
    }
    cout << *max_element(arr.begin(), arr.end());    
}