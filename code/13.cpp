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
    int romanToInt(string s) {
        int ans = 0, cur = 0, n = s.size();
        while(cur < n && s[cur] == 'M')
            ans += 1000, cur++;
        while(cur < n && (s[cur] == 'C' || s[cur] == 'D' || s[cur] == 'M')){
            if(s[cur] == 'D') {
                if(cur > 0 && s[cur - 1] == 'C') ans += 300;
                else ans += 500;
            }else if(s[cur] == 'M'){
                ans += 800;
            }else ans += 100;
            cur++;
        }
        while(cur < n && (s[cur] == 'L' || s[cur] == 'X' || s[cur] == 'C')){
            if(s[cur] == 'L') {
                if(cur > 0 && s[cur - 1] == 'X') ans += 30;
                else ans += 50;
            }else if(s[cur] == 'C'){
                ans += 80;
            }else ans += 10;
            cur++;
        }
        while(cur < n && (s[cur] == 'V' || s[cur] == 'I' || s[cur] == 'X')){
            if(s[cur] == 'V') {
                if(cur > 0 && s[cur - 1] == 'I') ans += 3;
                else ans += 5;
            }else if(s[cur] == 'X'){
                ans += 8;
            }else ans++;
            cur++;
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
