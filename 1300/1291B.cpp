//现在我们要在其中给变一些数字 但是我们知道这种题是要构造的，贪心
//注意我们的策略一定是灵活的 之前的死脑子根本不行！
#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++ i) cin >> arr[i];
        int maxL = 0, minR = n - 1;
        for(maxL; maxL < n; maxL ++){
            if(arr[maxL] < maxL){
                maxL --;
                break;
            }
        }
        for(minR; minR >= 0; -- minR)
            if(arr[minR] < n - minR - 1){
                minR ++;
                break;
            }
        //cout << minR << " " << maxL << endl;
        if(minR <= maxL) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}