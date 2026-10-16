#include <bits/stdc++.h>
using namespace std;
vector<int> x;  
int maxDistanceSub(int c){
    sort(x.begin(), x.end());
    if(c == 1){
        return 0;
    }
    int hi = (x[x.size() - 1] - x[0]) / (c - 1);
    int lo = 0;
    int ans = 0;
    while(lo <= hi){
        int temMax = lo + (hi - lo) / 2;
        int part =  1;
        int diff = 0; 
        for(int i = 1; i < x.size(); i ++){
            diff += x[i] - x[i - 1];
            if(diff >= temMax){
                diff = 0;
                part ++; 
                if(part == c){
                    break;
                }
            }    
        }
        if(part >= c){
            lo = temMax + 1;
            ans = temMax;
        }
        else{
            hi = temMax - 1;
        }
    }
    return ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int N; 
    cin >> N;
    for (int i = 0; i < N; i ++){
        int n;
        int c; 
        cin >> n >> c;
        x.resize(n, 0);
        for(int j = 0; j < n; j ++){
            cin >> x[j];
        }
        cout << maxDistanceSub(c) << '\n';
    }    
}