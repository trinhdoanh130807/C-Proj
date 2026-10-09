#include <bits/stdc++.h>
using namespace std;
int timeToSec (string tem){
    return stoi(tem.substr(0,2)) * 3600 + stoi(tem.substr(3,2)) * 60 + stoi(tem.substr(6,2));
}
bool checkPhoneNum(string tem){
    if (tem.size() != 10){
        return false;
    }
    for(int i = 0; i < 10; i++){
        if(tem[i] < '0' || tem[i] > '9'){
            return false;
        }
    }
    return true;
}
struct Node{
    string from;
    int duration;
    int nbCall;
    Node *rightChild;
    Node *leftChild;
};
Node *makeNode(string fr1, int dur, int numsCall ){
    Node *s = new Node;
    s -> from = fr1;
    s -> duration = dur;
    s -> nbCall = numsCall;
    s -> leftChild = NULL;
    s -> rightChild = NULL;
    return s;
}
Node *findNode(string nums, Node *r){
    if(r == NULL){
        return NULL;
    }
    if(nums == r -> from){
        return r;
    }
    if(nums < r -> from){
        return findNode(nums, r -> leftChild);
    }
    return findNode(nums, r -> rightChild);
}
Node *insertNode(string fr, int dur, int numCall, Node *r){
    if (r == NULL){
        return makeNode(fr, dur, numCall);
    }
    if(fr < r -> from){
        r -> leftChild = insertNode(fr,dur,numCall,r -> leftChild);
    }
    else if(fr > r -> from){
        r -> rightChild = insertNode(fr,dur,numCall,r -> rightChild);
    }
    else{
        r -> nbCall += numCall;
        r -> duration += dur;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string command, fromNum, toNum, date, fromTime, endTime;
    int flag = 1, total = 0;
    Node *root = NULL;
    while(1){
        cin >> command;
        if(command == "#"){
            break;
        }
        cin >> fromNum >> toNum >> date >> fromTime >> endTime;
        int dur = timeToSec(endTime) - timeToSec(fromTime);
        root = insertNode(fromNum,dur,1,root);
        if(!checkPhoneNum(fromNum) || !checkPhoneNum(toNum)){
            flag = 0;
        }
        total ++;
    }

    while(1){
        cin >> command;
        if(command == "?check_phone_number"){
            cout << flag << '\n';
        }
        else if(command == "?number_calls_from"){
            cin >> fromNum;
            if(findNode(fromNum,root) != NULL){
                cout << findNode(fromNum, root) -> nbCall << '\n';
            }
            else{
                cout << '0' << '\n';
            }
        }
        else if(command == "?number_total_calls"){
            cout << total << '\n';
        }
        else if (command == "?count_time_calls_from"){
            cin >> fromNum;
            if(findNode(fromNum,root) != NULL){
                cout << findNode(fromNum, root) -> duration << '\n';
            }
            else{
                cout << '0' << '\n';
            }
        }
        else{
            break;
        }
    }
}
/*
#include <bits/stdc++.h>
using namespace std;
int timeToSec (string tem){
    return stoi(tem.substr(0,2)) * 3600 + stoi(tem.substr(3,2)) * 60 + stoi(tem.substr(6,2));
}
bool checkPhoneNum(string tem){
    if (tem.size() != 10){
        return false;
    }
    for(int i = 0; i < 10; i++){
        if(tem[i] < '0' || tem[i] > '9'){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> NumberCall;
    map<string, int> TimeCall;
    string command, fromNum, toNum, date, fromTime, endTime;
    int flag = 1, total = 0;
    while(1){
        cin >> command;
        if( command == "#"){
            break;
        }
        cin >> fromNum >> toNum >> date >> fromTime >> endTime;
        int from = timeToSec(fromTime);
        int end = timeToSec(endTime);
        if(!checkPhoneNum(fromNum) || !checkPhoneNum(toNum)){
            flag = 0;
        }
        NumberCall[fromNum] ++;
        total ++;
        TimeCall[fromNum] += end - from;
    }
    while(1){
        cin >> command;
        if( command == "#"){
            break;
        }
        else if(command == "?check_phone_number"){
            cout << flag << "\n";
        }
        else if(command == "?number_calls_from"){
            cin >> fromNum;
            cout << NumberCall[fromNum] << "\n";
        }
        else if(command == "?number_total_calls"){
            cout << total << "\n";
        }
        else if(command == "?count_time_calls_from"){
            cin >> fromNum;
            cout << TimeCall[fromNum] << "\n";
        }
    }
}
*/
