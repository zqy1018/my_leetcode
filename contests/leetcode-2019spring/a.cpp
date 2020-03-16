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
char s[1005], t[1005];
int f[1005][1005];
void init(){
    cin >> s >> t;
}
void solve(){
    int n = strlen(s), m = strlen(t);
    memset(f, 0x3f, sizeof(f));
    f[0][m] = 0;
    for (int i = 1; i <= n; ++i){
        if(s[i - 1] == t[0])
            f[i][1] = f[i - 1][m] + 1;
        else
            f[i][1] = 0x3f3f3f3f;
        for (int j = 2; j <= m; ++j){
            if(s[i - 1] == t[j - 1])
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][m] + 1);
            else
                f[i][j] = f[i][j - 1];
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; ++i)
        ans = min(ans, f[n][i]);
    printf("%d\n", ans >= 0x3f3f3f3f ? -1: ans);
}
int main(){
	init();
	solve();
	return 0;
}
