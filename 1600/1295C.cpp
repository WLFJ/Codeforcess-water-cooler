/**
 * 打表查询模型
 * 在我们需要进行频繁查询子串的时候，将一些需要的位置存起来会减少复杂度。
 * 
 * 注意问题：
 * 使用跳转下标时：考虑下标越界、不存在下标、正常转移的处理，注意开始时候的记录
 * */
#include<iostream>
#include<string>
using namespace std;
const int MAXN = 1e5 + 10;
int nxt[MAXN]['z' + 1];
const int inf = 0x3f3f3f3f;
int main(void){
    int t;
    cin >> t;
    while(t --){
        for(int i = 0; i < MAXN; i ++){
            for(int j = 'a'; j <= 'z'; j ++){
                nxt[i][j] = inf;
            }
        }
        string s, z;
        cin >> s >> z;
        //首先最s串进行处理
        for(int i = s.length() - 1; i >= 0; -- i){
            //首先更新数据
            for(char c = 'a'; c <= 'z'; ++ c){
                nxt[i][c] = nxt[i + 1][c];
            }
            nxt[i][s[i]] = i;
        }
        //现在我们就得到每一个区间的最小位置了
        int lastPos = 0;
        int ans = 1;
        for(int i = 0; i < z.length(); i ++){
            if(lastPos == s.length()){
                lastPos = 0;
                ans ++;
            }
            if(nxt[lastPos][ z[i] ] == inf){
                if(nxt[0][z[i]] == inf){
                    ans = -1;
                    break;
                }
                ans ++;
                lastPos = nxt[0][ z[i] ] + 1;
            }else{
                lastPos = nxt[lastPos][ z[i] ] + 1;
            }
            //cout << lastPos << " " << z[i] << endl;
        }
        cout << ans << endl;
    }

    return 0;
}