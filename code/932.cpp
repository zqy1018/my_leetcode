#include <bits/stdc++.h>
using namespace std;
int n, a[1005], ans[1005];
int main(){
    cin >> n;
    int cur = 1;
    a[1] = 1;
    while(n < cur){
        for(int i = (cur << 1); i > cur; --i)
            a[i] = a[i - cur] << 1;
        for(int i = 1; i <= cur; ++i)
            a[i] = (a[i] << 1) - 1;
        cur <<= 1;
    }
    int cnt = 0;
    for(int i = 1; i <= cur; ++i)
        if(a[i] <= n)
            ans[++cnt] = a[i];
    return 0;
}