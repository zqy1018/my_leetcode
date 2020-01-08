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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<int> que;
		int l = beginWord.length(), pos = -1;
		auto judge = [&l](string& s1, string& s2){
			int cnt = 0;
			for (int i = 0; i < l; ++i)
				if (s1[i] != s2[i]){
					if (cnt) return false;
					++cnt;
				}
			return cnt == 1;
		};
		int n = wordList.size();
		vector<int> vis(n, 0);
		for (int i = 0; i < n; ++i){
			if (judge(beginWord, wordList[i]))
				que.push(i), vis[i] = 2;
			if (wordList[i] == endWord)	
				pos = i;
		}
		if (que.empty() || pos < 0) return 0;
		while (!que.empty() && !vis[pos]){
			int tp = que.front();
			que.pop();
			for (int i = 0; i < n; ++i){
				if (vis[i]) continue;
				if (judge(wordList[tp], wordList[i]))
					que.push(i), vis[i] = vis[tp] + 1;
			}
		}
		return vis[pos];
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
