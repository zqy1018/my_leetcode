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
    string minWindow(string s, string t) {
        vector<int> cnt(129, 0), cnt2(129, 0);
        int i = 0, j = -1, n = s.size(), m = t.size();
        int tot = 0, curtot = 0;
        int ans = n + 1, posi = -1, posj = -1;
        for (int k = 0; k < m; ++k){
            cnt2[t[k]]++;
            if(cnt2[t[k]] == 1) tot++;
        }
        for(; i < n && j < n - 1; ){
            while(j < n - 1 && curtot < tot){
                ++j, cnt[s[j]]++;
                if(cnt[s[j]] == cnt2[s[j]]) curtot++;
            }
            if(j == n - 1 && curtot < tot) break;
            while(i < j){
                if(cnt[s[i]] == cnt2[s[i]]) break;
                cnt[s[i]]--, ++i;
            }
            if(ans > j - i + 1)
                ans = j - i + 1, posi = i, posj = j;
            cnt[s[i]]--, --curtot, ++i;
        }
        if(ans == n + 1) return string("");
        return s.substr(posi, ans);
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
