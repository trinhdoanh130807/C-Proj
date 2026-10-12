#include <bits/stdc++.h>
using namespace std;
map<string, int> id;
vector<long long> money;
vector<bool> visited;
vector<vector<int>> transto;
int getID(string acc){
    if(id.count(acc) == 0){
        id.insert({acc, id.size()});
        transto.push_back(vector<int> ());
        money.push_back(0);
        visited.push_back(false);
    }
    return id.at(acc);
}
int acc;
bool cycle(int accID, int k){
    if(k == 1){
        for(int i : transto[accID]){
            if(i == acc){
                return true;
            }         
        }
        return false;
    }
    for(int i : transto[accID]){
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        if(cycle(i, k - 1)){
            visited[i] = false;
            return true;
        }
        visited[i] = false;
    }    
    return false;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    string from, to, timePoint, atm;
    int mon;
    int total = 0;
    long long totalMoney = 0;
    while(cin >> from && from != "#"){
        cin >> to >> mon >> timePoint >> atm;
        total ++;
        totalMoney += mon;
        int u = getID(from);
        int v = getID(to);
        money[u] += mon;
        transto[u].push_back(v);       
    }    
    string command;
    while (cin >> command && command != "#"){
        if(command == "?number_transactions"){
            cout << total << '\n';
        }
        else if(command == "?total_money_transaction"){
            cout << totalMoney << '\n';
        }
        else if(command == "?list_sorted_accounts"){
            bool first = true; 
            for (auto &tem : id){
                if(first){
                    cout << tem.first;
                    first = !first;
                    continue;
                }
                cout << ' ' << tem.first;
            }
            cout << '\n';
        }
        else if(command == "?total_money_transaction_from"){
            cin >> from;
            if (id.find(from) == id.end()){
                cout << 0 << '\n';
            }
            else{
                cout << money[id.at(from)] << '\n';
            }
            
        }
        else if(command == "?inspect_cycle"){
            int k;
            string temAcc;
            cin >> temAcc >> k;
            if(id.find(temAcc) == id.end() || k > id.size()){
                cout << 0 << '\n';
            }
            else{
                acc = getID(temAcc);
                visited[acc] = true;
                cout << (cycle(acc, k)? 1 : 0) << '\n';
                visited[acc] = false;
            }
            
        }
    }
}