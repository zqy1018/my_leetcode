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
    int countPrimeSetBits(int L, int R) {
        int notprime[20] = {0};
        notprime[2] = notprime[3] = notprime[5] = notprime[7] = 1;
        notprime[11] = notprime[13] = notprime[17] = notprime[19] = 1;
        int ans = 0;
        while (R >= L){
            int cnt = 0, tmp = L;
            while (tmp > 0)
                tmp -= (tmp & (-tmp)), ++cnt;
            ans += notprime[cnt];
            ++L;
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

