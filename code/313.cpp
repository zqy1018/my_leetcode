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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        vector<int> vec(1, 1);
        int k = primes.size();
        vector<int> pos(k, 0);
        for (int i = 1; i < n; ++i){
            int res = 2147483647;
            for (int j = 0; j < k; ++j)
                res = min(res, vec[pos[j]] * primes[j]);
            for (int j = 0; j < k; ++j)
                if(res == vec[pos[j]] * primes[j]) pos[j]++;
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
