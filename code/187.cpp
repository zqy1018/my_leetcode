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
    vector<string> findRepeatedDnaSequences(string s) {
        bitset<1048576> bt, bt2;
		vector<string> ans;
		int n = s.size(), cur = 0;
		if(n < 10) return vector<string>();
		for (int i = 0; i < 10; ++i){
			if(s[i] == 'A') cur = cur << 2;
			if(s[i] == 'G') cur = cur << 2 | 1;
			if(s[i] == 'C') cur = cur << 2 | 2;
			if(s[i] == 'T') cur = cur << 2 | 3;
		}
		for (int i = 10; i < n; ++i){
			if(bt[cur] && !bt2[cur]) ans.push_back(s.substr(i - 10, 10)), bt2.set(cur);
			bt.set(cur);
			cur = (cur << 2) & 1048575;
			if(s[i] == 'G') cur |= 1;
			if(s[i] == 'C') cur |= 2;
			if(s[i] == 'T') cur |= 3;
		}
		if(bt[cur] && !bt2[cur]) ans.push_back(s.substr(n - 10, 10)), bt2.set(cur);
		bt.set(cur);
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
