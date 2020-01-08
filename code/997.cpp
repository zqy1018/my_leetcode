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
    int findJudge(int N, vector<vector<int>>& trust) {
        bitset<1003> in[1003], out[1003];
        int n = trust.size();
        for (int i = 0; i < n; ++i){
            int a = trust[i][0], b = trust[i][1];
            in[b].set(a), out[a].set(b);
        }
        int tg = -1;
        for (int i = 1; i <= N; ++i){
            if(in[i].count() == N - 1 && out[i].count() == 0){
                if(tg < 0) tg = i;
                else return -1;
            }
        }
        return tg;
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
