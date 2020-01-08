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
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if(!len1 || !len2) return len1 + len2;
        vector<vector<int> > f(len1 + 1, vector<int>());
        for (int i = 0; i <= len1; ++i){
            f[i].resize(len2 + 1);
        }
        for (int i = 0; i <= len1; ++i)
            f[i][0] = i;
        for (int i = 0; i <= len2; ++i)
            f[0][i] = i;
        for (int i = 1; i <= len1; ++i)
            for (int j = 1; j <= len2; ++j){
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                if(word1[i - 1] == word2[j - 1])
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                else
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            }
        return f[len1][len2];
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
