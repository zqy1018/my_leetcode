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
    int longestRepeatingSubstring(string S) {
        int n = S.size();
        vector<int> fail;
        int ans = 0;
        for (int i = 0; i < n; ++i){
            fail = vector<int>(n - i + 3);
            fail[0] = -1;
            for(int t = 1, j = -1; t < n - i; ++t){
                while(j > -1 && S[i + t] != S[i + j + 1])
                    j = fail[j];
                if(S[i + t] == S[i + j + 1]){
                    fail[t] = ++j;
                    ans = max(ans, j + 1);
                }else
                    fail[t] = -1;
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
