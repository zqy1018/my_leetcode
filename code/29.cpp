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
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648){
            if(divisor == -1)
                return 2147483647;
            if(divisor == 1)
                return -2147483648;
        }
        int flag = 1;
        if((dividend >= 0 && divisor >= 0) || (dividend <= 0 && divisor <= 0))
            flag = 1;
        else
            flag = -1;
        if(dividend > 0)
            dividend = -dividend;
        if(divisor > 0)
            divisor = -divisor;
        if(dividend > divisor) return 0;
        int ans = 1, curk = 1;
        long long curd = divisor, curkk = divisor;
        while(curk){
            if(curd + curkk >= dividend){
                ans += curk, curd += curkk;
                curk += curk, curkk += curkk;
            }else{
                curk >>= 1, curkk >>= 1;
            }
        }
        return flag * ans;
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
