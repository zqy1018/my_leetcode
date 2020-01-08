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
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > f(m + 1, vector<int>(n + 1, 0));
        int t = strs.size(), ans = 0;
        for (int i = 0; i < t; ++i){
            int cnt0 = 0, cnt1 = 0;
            for (char c: strs[i]){
                if(c == '0') cnt0++;
                else cnt1++;
            }
            for (int j = m; j >= cnt0; --j)
                for (int k = n; k >= cnt1; --k)
                    f[j][k] = max(f[j][k], f[j - cnt0][k - cnt1] + 1), 
                    ans = max(ans, f[j][k]);
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
