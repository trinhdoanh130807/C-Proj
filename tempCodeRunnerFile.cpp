#include <bits/stdc++.h>
using namespace std;
int n;
double d(pair<double, double> a, pair<double,double> b){
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
bool comparator(const pair<double, double> &x, const pair<double, double> &y){
    return x.second < y.second;
}
void mergeY(vector<pair<double, double>> &o, vector<pair<double, double>> &tem, int l, int r){
    int mid = l + (r - l) / 2;
    int i = l, j = mid, k = l;
    while(i < mid && j < r){
        if(o[i].second < o[j].second){
            tem[k ++] = o[i ++];
        }
        else{
            tem[k ++] = o[j ++];
        }
    }
    while(i < mid){
        tem[k ++] = o[i ++];
    }
    while(j < r){
        tem[k ++] = o[j ++];
    }
    for(int m = l; m < r; m ++){
        o[m] = tem[m];
    }
}
double Solve(vector<pair<double, double>> &o, vector<pair<double, double>> &tem, int l, int r){
    if(r - l <= 3){
        double minTem = DBL_MAX;
        for(int i = l; i < r; i ++){
            for(int j = i + 1; j < r; j ++){
                minTem = min(minTem, d(o[i], o[j]));
            }
        }
        sort(o.begin() + l, o.begin() + r, comparator);

        return minTem;
    }
    int mid = l + (r - l) / 2;
    double xMid = o[mid].first;
    double dl = Solve(o, tem, l, mid);
    double dr = Solve(o, tem, mid, r);
    double temd = min(dl, dr);
    mergeY(o, tem, l, r);
    vector<pair<double, double>> strip;
    for(int i = l; i < r; i ++){
        if((o[i].first - xMid) * (o[i].first - xMid) < temd) strip.push_back(o[i]); 
    }    
    for(int i = 0; i < strip.size(); i ++){
        for(int j = i + 1; j < strip.size(); j ++){
            if((strip[i].second - strip[j].second) * (strip[i].second - strip[j].second) < temd){
                temd = min(temd, d(strip[i], strip[j]));
            }
            else break;
        }
    }
    return temd;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> n;
    vector<pair<double, double>> o(n);
    vector<pair<double, double>> tem(n);
    for(int i = 0; i < n; i ++){
        cin >> o[i].first >> o[i].second;
    }
    sort(o.begin(), o.end());
    double res = Solve(o, tem, 0, n);
    cout << fixed << setprecision(6) << sqrt(res);
    return 0;
}