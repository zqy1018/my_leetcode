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
    string smallestEquivalentString(string A, string B, string S) {
        vector<vector<int> > g(30, vector<int>(30, 0));
        for (int i = 0; i < A.size(); ++i){
            g[A[i] - 'a'][B[i] - 'a'] = g[B[i] - 'a'][A[i] - 'a'] = 1;
        }
        for (int i = 0; i < 26; ++i)
            g[i][i] = 1;
        for (int k = 0; k < 26; ++k){
            for (int i = 0; i < 26; ++i){
                for (int j = 0; j < 26; ++j){
                    g[i][j] = max(g[i][j], (g[i][k] & g[k][j]));
                }
            }
        }
        vector<int> minn(30, 3333);
        for (int i = 0; i < 26; ++i){
            for (int j = 0; j < 26; ++j){
                if(g[i][j]) minn[i] = min(minn[i], j);
            }
        }
        string ans = string(S.size(), 'z');
        for (int i = 0; i < S.size(); ++i){
            ans[i] = minn[S[i] - 'a'] + 'a';
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
