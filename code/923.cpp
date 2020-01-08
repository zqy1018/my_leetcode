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
    int threeSumMulti(vector<int>& A, int target) {
        vector<int> cnt(target + 1, 0);
        vector<int> rcnt(101, 0);
        for (int i: A) rcnt[i]++;
        int ans = 0, n = A.size();
        for (int i = 0; i <= 100; ++i){
            if(i > target) break;
            ans += cnt[target - i];
            if(ans >= 1000000007) ans -= 1000000007;
            for (int j = 0; j < i; ++j)
                if(i + j <= target)
                    cnt[i + j] += rcnt[i] * rcnt[j];
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
