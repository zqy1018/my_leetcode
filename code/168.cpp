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
    string convertToTitle(int n) {
        string ans("");
        if(!n) ans = "A";
        while(n){
            if(n % 26) {
                char c = 'Z';
                ans = c + ans;
                n /= 26, n--;
            }else{
                char c = 'A' + n % 26;
                ans = c + ans;
                n /= 26;
            }
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
