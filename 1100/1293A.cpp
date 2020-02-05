//给定一个序列 有一些地方关闭了 现在要寻找s位置最近的饭厅
//我们可以使用暴力去遍历一下
//所以说如果我们的直觉解法很复杂时，一定要关注数据量！尤其是注意黑体字和单独重复的说明！
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int n, s, k;
        cin >> n >> s >> k;
        map<int, int> mem;
        for(int i = 0; i < k; i ++){
            int floor;
            cin >> floor;
            mem[floor] ++;
        }
        int minAns = 0x3f3f3f3f;
        for(int test = max(1, s - 1000); test <= min(n, s + 1000); test ++){
            if(mem[test] == 0){
                minAns = min(minAns, abs(s - test));
            }
        }
        cout << minAns << endl;
    }

    return 0;
}
