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
    string solveEquation(string equation) {
        int lv = 0, rv = 0, i = 0;
		int f1 = 1, f2 = 1, coef = 0;
		for (char c: equation){
			if (c == 'x'){
				if (!coef) lv += f2 * f1;
				else lv += coef * f2 * f1;
				coef = 0, f1 = 1;
				continue;
			}else if (isdigit(c)){
				coef = coef * 10 + c - '0';
				continue;
			}
			if (coef) rv -= coef * f2 * f1, coef = 0;
			if (c == '='){
				f1 = 1, f2 = -1;
			}else if (c == '+'){
				f1 = 1;
			}else if (c == '-'){
				f1 = -1;
			}
		}
		if (coef) rv -= coef * f2 * f1;
		if (!lv) return (rv == 0 ? "Infinite solutions": "No solution");
		return "x=" + to_string(rv / lv);
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
