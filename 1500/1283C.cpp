//如果题目所说的情景很合适 那么我们可以详细分析其中的奥秘……
#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 2e5 + 10;
int mem[MAXN];
int main(void){
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> notSend;
    vector<int> notReceieve;
    for(int i = 1; i <= n; ++ i){
        cin >> arr[i];
        mem[arr[i]] ++;
        if(arr[i] == 0) notSend.push_back(i);
    }
    for(int i = 1; i <= n; i ++){
        if(mem[i] == 0) notReceieve.push_back(i);
    }
    for(int i = 0; i < notReceieve.size(); ++ i){
        if(notReceieve[i] == notSend[i]){
            swap(notReceieve[i], notReceieve[ (i + 1) % notReceieve.size() ]);
        }
    }
    int p = 0;
    for(int i = 1; i <= n; i ++){
        if(i != 1) cout << " ";
        if(arr[i] == 0) cout << notReceieve[p ++];
        else cout << arr[i];
    }
    cout << endl;


    return 0;
}