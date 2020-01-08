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
    int smallestRepunitDivByK(int K) {
        if(gcd(K, 10) != 1) return -1;
        int ans = getPhi(K * 9);
        int pp = ans;
        for(int i = 1; i * i <= pp; ++i){
            if(pp % i == 0){
                if(poww(10, i, K) == 1)
                    ans = min(ans, i);
                if(poww(10, pp / i, K) == 1)
                    ans = min(ans, pp / i);
            }
        }
        return ans == 0 ? K: ans;
    }
private:
    int gcd(int a, int b){
        return (!b) ? a: gcd(b, a % b);
    }
    int getPhi(int x){
        int t = x, res = x;
        for (int i = 2; i * i <= x; ++i){
            if(t % i == 0){
                do{
                    t /= i;
                }while(t % i == 0);
                res /= i, res *= (i - 1);
            }
            if(t == 1) break;
        }
        if(t > 1) res /= t, res *= (t - 1);
        return res;
    }
    int poww(int a, int b, int c){
        int res = 1;
        while(b){
            if(b & 1) res = 1ll * res * a % c;
            a = 1ll * a * a % c;
            b >>= 1;
        }
        return res;
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
