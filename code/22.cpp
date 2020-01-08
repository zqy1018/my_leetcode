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
    char *tmp;
    vector<string> ans;
    void dfs(int curl, int curr, int cur, int d){
        if(!curl && !curr){
            tmp[d] = '\0';
            ans.push_back(string(tmp));
            return ;
        }
        if(cur == 0){
            tmp[d] = '(';
            dfs(curl - 1, curr, cur + 1, d + 1);
        }else if(!curl){
            tmp[d] = ')';
            dfs(curl, curr - 1, cur - 1, d + 1);
        }else{
            tmp[d] = '(';
            dfs(curl - 1, curr, cur + 1, d + 1);
            tmp[d] = ')';
            dfs(curl, curr - 1, cur - 1, d + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        tmp = new char[n + n + 1];
        dfs(n, n, 0, 0);
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
