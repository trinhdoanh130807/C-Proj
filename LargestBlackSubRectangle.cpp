#include <bits/stdc++.h>
using namespace std;
vector<int> Height;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    int maxS = 0;
    vector<vector<int>> Rec;
    cin >> m >> n;
    Rec.assign(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> Rec[i][j];
        }
    }
    for(int i = 0; i <= n + 1; i ++){
        Height.push_back(0);
    }
    for(int i = 0; i < m; i ++){
        stack<int> Tem;
        Tem.push(0);
        for(int j = 0; j < n; j ++){
            if(Rec[i][j] == 0){
                Height[j + 1] = 0;
            }
            else{
                Height[j + 1] ++;
            }
        }
        for(int k = 1; k <= n + 1; k ++){
            if(Height[k] >= Height[Tem.top()]){
                Tem.push(k);
            }
            else{
                while(Height[k] < Height[Tem.top()]){
                    int height = Height[Tem.top()];
                    Tem.pop();
                    int s = height * (k - Tem.top() - 1);
                    maxS = max(maxS, s);
                }
                Tem.push(k);
            }
        }
    }
    cout << maxS;

}
/*
#include <bits/stdc++.h>
using namespace std;
vector<int> Height;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    int maxS = 0;
    int cinTem;
    cin >> m >> n;
    for(int i = 0; i <= n + 1; i ++){
        Height.push_back(0);
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> cinTem;
            if(cinTem == 0){
                Height[j + 1] = 0;
            }
            else{
                Height[j + 1] ++;
            }
        }
        stack<int> Tem;
        Tem.push(0);
        for(int j = 1; j <= n + 1; j++){
            if(Height[j] >= Height[Tem.top()]){
                Tem.push(j);
            }
            else{
                while(Height[j] < Height[Tem.top()]){
                    int height = Height[Tem.top()];
                    Tem.pop();
                    int s = height * (j - Tem.top() - 1);
                    maxS = max(maxS, s);
                }
                Tem.push(j);
            }
        }
    }
    cout << maxS;
}
*/
