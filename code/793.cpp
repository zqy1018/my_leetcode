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
    int preimageSizeFZF(int K) {
        typedef long long ll;
        auto calc = [](ll x) -> int{
            int res = 0;
            ll cur = 5;
            while(x >= cur)
                res += x / cur, cur *= 5ll;
            return res;
        };
        ll l1 = 0, r1 = K * 5ll;
        while(l1 < r1){
            ll mid = (l1 + r1) >> 1;
            if(calc(mid) < K)
                l1 = mid + 1;
            else r1 = mid;
        }
        ll l2 = 0, r2 = K * 5ll;
        while(l2 < r2){
            ll mid = (l2 + r2) >> 1;
            if(calc(mid) <= K)
                l2 = mid + 1;
            else r2 = mid;
        }
        return r2 - r1;
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
