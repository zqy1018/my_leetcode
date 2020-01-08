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
int fa[2005], siz[2005];
int Find(int x){
	return (x == fa[x] ? x: (fa[x] = Find(fa[x])));
}
void Union(int x, int y){
	int u = Find(x), v = Find(y);
	if (u == v) return ;
	if (siz[u] > siz[v])
		fa[v] = u, siz[u] += siz[v];
	else 
		fa[u] = v, siz[v] += siz[u];
}
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 52; ++i)
			fa[i] = i, siz[i] = 1;
		for (string& s: equations){
			int u = s[0] - 'a', v = s[3] - 'a'	;
			if (s[1] == '!'){
				if (Find(u) == Find(v)) return false;
				Union(u, v + 26), Union(u + 26, v);
			}else {
				if (Find(u) == Find(v + 26)) return false;
				Union(u, v), Union(u + 26, v + 26);
			}
		}
		return true;
    }
};
Solution sol;
void init(){
    
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
