//首先我们想到了将输入的数字都取mod
//如果0～k-1都存在的话我们就可以扩展一个区间 直到无法扩展为止 在这个时候我们要使用消除模型，也就是说及时将信息处理了
//动态 + 在数列上做加减操作
#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int q, x;
    cin >> q >> x;
    int ans = 0;
    vector<int> arr(x);
    for(int i = 0; i < q; i ++){
        int num;
        cin >> num;
        arr[num % x] ++;
        while(arr[ans % x]) arr[ans % x] --, ans ++;
        cout << ans << endl;
    }
    return 0;
}