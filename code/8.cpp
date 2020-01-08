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
    int myAtoi(string str) {
        int n = str.size();
        int cur = 0, f = 1;
        long long ans = 0;
        while(cur < n && isspace(str[cur]))
            cur++;
        if(cur == n || (str[cur] != '-' && str[cur] != '+' && !isdigit(str[cur])))
            return 0;
        if(!isdigit(str[cur])) {
            if(str[cur] == '-') f = -1;
            cur++;
        }
        while(cur < n && isdigit(str[cur])){
            ans = ans * 10ll + str[cur] - '0', cur++;
            if(ans >= 2147483648ll){
                if(f > 0) return 2147483647;
                else return -2147483648;
            }
        }
        return f * ans;
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
