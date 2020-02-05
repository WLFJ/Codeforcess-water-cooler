#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    long long ans = 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    vector<int> ans(n);
    for(int i = 0; i < n; i ++){
        arr[i] %= a + b;
        if(arr[i] == 0) arr[i] += a + b;
        ans[i] += arr[i] / a + (bool)(arr[i] % a) - 1;
    }
    sort(ans.begin(), ans.end());
    int aa = 0;
    int cnt = 0;
    for(int i = 0; i < ans.size(); i ++){
        if(cnt + ans[i] <= k) aa ++;
        else break;
    }
    cout << aa << endl;


    return 0;
}