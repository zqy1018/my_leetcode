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
    int n, ans;
    void dfs(string& A, string& B, int st, int cur){
        if(cur == n){
            ans = min(ans, st);
            return ;
        }
        while(cur < n && A[cur] == B[cur])
            ++cur;
        if(cur == n){
            ans = min(ans, st);
            return ;
        }

        for (int i = cur + 1; i < n && st < ans - 1; ++i){
            if(A[i] == B[cur]){
                swap(A[i], A[cur]), dfs(A, B, st + 1, cur + 1), 
                swap(A[i], A[cur]);
            }
        }
    }
    int kSimilarity(string A, string B) {
        n = A.length();
        ans = n;
        dfs(A, B, 0, 0);
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
