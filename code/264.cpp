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
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        vector<int> vec(1, 1);
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 1; i < n; ++i){
            int res = min(vec[c1] * 2, min(vec[c2] * 3, vec[c3] * 5));
            if(res == vec[c1] * 2) c1++;
            if(res == vec[c2] * 3) c2++;
            if(res == vec[c3] * 5) c3++;
            vec.push_back(res);
        }
        return vec.back();
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
