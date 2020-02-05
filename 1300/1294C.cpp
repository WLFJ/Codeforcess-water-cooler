//这里使用了分解质因数的思想，只要遇到乘法、能否组成之类的问题，都往这个方面取考虑。
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int num;
        cin >> num;
        vector<int> arr;
        for(int i = 2; i * i <= num; i ++){
            if(num % i == 0){
                arr.push_back(i);
                arr.push_back(num / i);
            }
        }
        sort(arr.begin(), arr.end());
        for(int a = 0; a < arr.size(); a ++){
            for(int b = a + 1; b < arr.size(); b ++){
                for(int c = b + 1; c < arr.size(); c ++){
                    if(arr[a] * arr[b] * arr[c] == num){
                        cout << "YES" << endl << arr[a] << " " << arr[b] << " " << arr[c] << endl;
                        goto ok;
                    }
                }
            }
        }
        cout << "NO" << endl;
        ok:;
    }


    return 0;
}