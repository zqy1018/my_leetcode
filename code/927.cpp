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
int nxt[30005], lis[30005];
int nxt_one_to_r[30005], nxt_one_to_l[30005];
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
		int n = A.size();
		int nn = 0;
		for (int i = 0; i < n; ++i){
			if (A[i] || nn > 0)	
				lis[nn++] = A[i];
		}
		if (!nn) return vector<int>{0, 2};
		nxt[0] = -1;
		for (int i = 1, j = -1; i < nn; ++i){
			while (j > -1 && lis[i] != lis[j + 1])
				j = nxt[j];
			if (lis[i] == lis[j + 1])
				nxt[i] = ++j;
			else nxt[i] = -1;
		}
		nxt_one_to_l[nn] = nn;
		for (int i = nn - 1; i >= 0; --i)
			nxt_one_to_l[i]	= (lis[i] ? i: nxt_one_to_l[i + 1]);
		nxt_one_to_r[0] = (lis[0] ? 0: -1);
		for (int i = 1; i < nn; ++i)
			nxt_one_to_r[i]	= (lis[i] ? i: nxt_one_to_r[i - 1]);
		int tmp = nxt[nn - 1];
		while (tmp > -1){
			int len = tmp + 1, lst = nn - len - 1;
			int new_st = nxt_one_to_l[len], new_ed = new_st + tmp;
			if (nxt_one_to_r[new_ed] == nxt_one_to_r[lst]){
				int ttmp = nxt[new_ed];
				while (ttmp > -1){
					if (ttmp == len - 1) return vector<int>{tmp, new_ed + 1};
					ttmp = nxt[ttmp];
				}
			}
		}
		return vector<int>{-1, -1};
    }
};
// 后往前找第一个非零，前往后找第一个非零，然后 check 中间部分？
// 构建 fail 树，在上面跑把
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
