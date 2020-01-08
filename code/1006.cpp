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
    int clumsy(int N) {
        if(N == 1) return 1;
        if(N == 2) return 2;
        if(N == 3) return 6;
        int res = 0;
        for (int i = N; i - 4 >= 0; i -= 4){
            if(i == N) res += i * (i - 1) / (i - 2) + i - 3;
            else res += i - 3 - i * (i - 1) / (i - 2);
        }
        if(N % 4 == 1) res -= 1;
        if(N % 4 == 2) res -= 2;
        if(N % 4 == 3) res -= 6;
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
