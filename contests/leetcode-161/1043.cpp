#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, que[1000005], hd, tl;
int lch[1000005] = {0}, rch[1000005] = {0};
void init(){
    n = read();
    for (int i = 2; i <= n; ++i){
        int fa = read() + 1;
        if (lch[fa] == 0) lch[fa] = i;
        else rch[fa] = i;
    }
}
void solve(){
    hd = tl = 0;
    que[tl++] = 1;
    while (tl > hd){
        int v = que[hd++];
        if (lch[v]) que[tl++] = lch[v];
        else break;
        if (rch[v]) que[tl++] = rch[v];
        else break;
    }
    printf("%s\n", (tl == n ? "true": "false"));
}
int main(){
    init();
    solve();
    return 0;
}
