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
    int candy(vector<int>& ratings) {
        int ans = 1, n = ratings.size(), lst = 1;
        int len = 1, st = 1;
        for (int i = 1; i < n; ++i){
            if (ratings[i] > ratings[i - 1]){
                ans += lst + 1, ++lst;
                ans += (len * (len - 1) >> 1) + max(len - st, 0);
                len = 1, st = lst;
            }else if (ratings[i] == ratings[i - 1]){
                ++ans, lst = 1;
                ans += (len * (len - 1) >> 1) + max(len - st, 0);
                len = 1, st = lst;
            }else {
                lst = 1, ++len;
            }
        }
        ans += (len * (len - 1) >> 1) + max(len - st, 0);
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
