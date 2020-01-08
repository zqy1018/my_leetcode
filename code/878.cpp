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
    int gcd(int a, int b){
        return (!b) ? a: gcd(b, a % b);
    }
    int nthMagicalNumber(int N, int A, int B) {
        int lcm = A * B / gcd(A, B);
        int r = lcm / A + lcm / B - 1;
        int ans = 1ll * (N / r) * lcm % 1000000007;
        N %= r;
        if(N){
            int j = A, k = B, res;
            for (int i = 0; i < N; ++i){
                if(j <= k) res = j, j += A;
                else res = k, k += B;
            }
            ans = (ans + res) % 1000000007;
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
