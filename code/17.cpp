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
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(!digits.size()) return ans;
        string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.push_back("");
        for (char c: digits){
            int n = ans.size(), len = s[c - '0'].size();
            for (int i = 0; i < n; ++i)
                for (int j = 1; j < len; ++j)
                    ans.push_back(ans[i] + s[c - '0'][j]);
            for (int i = 0; i < n; ++i)
                ans[i].append(1, s[c - '0'][0]);
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
