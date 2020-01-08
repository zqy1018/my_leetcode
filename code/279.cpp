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
    int numSquares(int n) {
        int tmp = n;
        while(tmp & 3 == 0)
            tmp >>= 2;
        if(tmp % 8 == 7) return 4;
        int ssqrt = (int)floor(sqrt(n) + 0.5);
        if(ssqrt * ssqrt > n) ssqrt--;
        if(ssqrt * ssqrt == n) return 1;
        int l = 1, r = ssqrt;
        while(l < r){
            int res = l * l + r * r - n;
            if(res > 0)
                r--;
            else if(res < 0)
                l++;
            else return 2;
        }
        if(2 * l * l == n) return 2;
        return 3;
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
