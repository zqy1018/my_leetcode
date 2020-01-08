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
    int minSteps(int n) {
        int ans = 0, t = n;
        for (int i = 2; i * i <= n; ++i){
            if(t % i == 0){
                do{
                    ans += i;
                    t /= i;
                }while(t % i == 0);
            }
            if(t == 1) break;
        }
        if(t > 1) ans += t;
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
