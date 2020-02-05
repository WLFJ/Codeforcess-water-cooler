//说是删除 我们要往构造上去想！
#include<iostream>
#include<string>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int len;
        string s;
        cin >> len >> s;
        int cnt = 0;
        string ans;
        for(char c : s){
            if((c - '0') & 1){
                ans += c;
                cnt ++;
            }
            if(cnt == 2) break;
        }
        if(cnt == 2) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}