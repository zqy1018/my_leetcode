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
    vector<vector<bool> > f;
    int ans;
    void dfs(int used, int cur, int lst, vector<int>& A){
        int n = A.size();
        if(cur == n){
            ans++;
            return ;
        }
        for (int i = 0; i < n; ){
            int j = i;
            while(j < n && A[i] == A[j])
                ++j;
            while(i < j && ((1 << i) & used))
                ++i;
            if(i == j) continue;
            if(!f[lst][i]){
                i = j;
                continue;
            }
            dfs(used | (1 << i), cur + 1, i, A);
            i = j;
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        f = vector<vector<bool> >(n, vector<bool>(n, 0));
        auto judge = [](int x){
            int sqt = (int)floor(sqrt(x) + 0.5);
            if(sqt * sqt > x) sqt--;
            return sqt * sqt == x;
        };
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j){
                if(judge(A[i] + A[j]))
                    f[i][j] = f[j][i] = true;
            }
        ans = 0;
        for (int i = 0; i < n; ){
            int j = i;
            while(j < n && A[i] == A[j])
                ++j;
            dfs(1 << i, 1, i, A);
            i = j;
        }    
        return ans;
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
