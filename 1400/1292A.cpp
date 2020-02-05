//动态的问题
//首先的想法是将每一个位置打上标记 之后检查是否被封锁了
//现在我们看一下数据量 很大 说明检查一定会超时 那么我们就之关注局部的更改！
//思想：动态修改
#include<iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int maze[MAXN][2];
int main(void){
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    while(q --){
        int y, x;
        cin >> y >> x;
        y --;
        maze[x][y] = 1 - maze[x][y];
        //下面开始检查 算奇偶数估计不行呀！
        for(int i = -1; i <= 1; i ++){
            if(maze[x + i][1 - y]){
                if(maze[x][y] % 2 && maze[x + i][1 - y] % 2) cnt ++;
                else cnt --;
            }
        }
        //cout << cnt << endl;//但是现在出了什么问题呢？
        cout << (cnt ? "NO" : "YES") << endl;
    }
    return 0;
}