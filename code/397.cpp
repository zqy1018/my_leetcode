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
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 2147483647) return 32;
        if(n & 1){
            if((n & 3) == 3) return integerReplacement((n + 1) >> 2) + 3;
            else return integerReplacement((n - 1) >> 2) + 3;
        } 
        return integerReplacement(n >> 1) + 1;
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
