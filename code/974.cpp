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
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size(), ss = 0, ans = 0;
        vector<int> cnt(K, 0);
        cnt[0] = 1;
        for (int i = 0; i < n; ++i){
            ss = (ss + A[i]) % K;
            if(ss < 0) ss += K;
            ans += cnt[ss], cnt[ss]++;
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
