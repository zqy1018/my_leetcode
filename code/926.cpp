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
    int minFlipsMonoIncr(string S) {
        int ss = 0, curs = 0;
        for (char c: S)
            ss += c - '0';
        int n = S.size(), ans = n - ss;
        for (int i = 0; i < n; ++i)
            curs += S[i] - '0', ans = min(ans, curs + curs + n - i - 1 - ss);
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
