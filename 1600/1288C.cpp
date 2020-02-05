//排列组合类的题目 我们的策略就是抽象出要计算的排列组合是什么
//我们已经在脑海中想想到其样子了 那么我们能否通过状态转移的办法将其求出来呢？
//组合数学关键是分解出子部分 之后一环套一环！
#include<iostream>
#define int long long
using namespace std;
const int MAXN = 1005, MAXM = 15;
int dp[MAXN][MAXM];
int MOD = 1e9 + 7;
int DP(int n, int m){//取值 长度
    if(dp[n][m]) return dp[n][m];
    if(m == 1){
        return dp[n][m] = 1;
    }
    for(int i = 1; i <= n; i ++){
        dp[n][m] = (dp[n][m] + DP(i, m - 1)) % MOD;
    }
    return dp[n][m];
}
int k[MAXN][MAXM];
int K(int n, int m){
    if(k[n][m]) return k[n][m];
    for(int i = 1; i <= n; i ++){
        k[n][m] = (k[n][m] + DP(i, m)) % MOD;
    }
    return k[n][m];
}
int g[MAXN][MAXM];
int G(int n, int m){
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        ans = (ans + DP(i, m) * K(n - i + 1, m) * 1LL % MOD) % MOD;
    }
    return ans % MOD;
}
signed main(void){
    //首先我们先将二维长度的表打出来
    //先初始化
    int n, m;
    cin >> n >> m;
    cout << G(n, m) << endl;
    return 0;
}