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
    bool detectCapitalUse(string word) {
        int n = word.size();
        int flag1 = -1, flag2 = -1;
        for(int i = 0; i < n; ++i){
            if(islower(word[i])) flag2 = i;
            else flag1 = i;
        }
        return (flag1 == -1 || flag2 == -1 || flag1 == 0);
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
