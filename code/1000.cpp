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
class Solution {
public:
    vector<vector<int>> f;
    vector<int> sum;
    int KK;
    void dfs(int k, int l, int r, int acc, int& res){
        if (k == 1){
            acc += sum[r + 1] - sum[l] + f[l][r];
            res = min(res, acc);
            return ;
        }
        for (int t = 0; t + k - 1 <= r - l; t += (KK - 1))
            dfs(k - 1, l + t + 1, r, acc + sum[l + t + 1] - sum[l] + f[l][l + t], res);
    }
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n - 1) % (K - 1)) return -1;
        f = vector<vector<int>>(n, vector<int>(n, 0x3f3f3f3f));
        sum = vector<int>(n + 1, 0);
        KK = K;
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + stones[i], 
            f[i][i] = 0; 
        for (int i = K - 1; i < n; i += K - 1)
            for (int j = 0; j + i < n; ++j)
                dfs(K, j, j + i, 0, f[j][j + i]);
        return f[0][n - 1];
    }
};
Solution sol;
void init(){
    vector<int> tt{3,5,1,2,6};
    cout << sol.mergeStones(tt, 3);
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
