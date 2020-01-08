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
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        char aans[6];
        auto cnt = [](int x) -> int{
            int res = 0;
            while(x) 
                res++, x -= (x & (-x));
            return res;
        };
        for (int i = 0; i < num; ++i){
            for (int j = 0; j < 12; ++j){
                if(cnt(j) != i) continue;
                for (int k = 0; k < 60; ++k){
                    if(cnt(k) != num - i) continue;
                    sprintf(aans, "%d:%02d", j, k);
                    ans.push_back(string(aans));
                }
            }
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
