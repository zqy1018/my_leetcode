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
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int len = max(n1, n2), x = 0;
        vector<char> res;
        for (int i = 0; i < len; ++i){
            if(n1 - i - 1 >= 0) x += num1[n1 - i - 1] - '0';
            if(n2 - i - 1 >= 0) x += num2[n2 - i - 1] - '0';
            res.push_back('0' + x % 10), x /= 10;
        }
        if(x) res.push_back('0' + x), len++;
        string ans(len, '0');
        for (int i = len - 1; i >= 0; --i)
            ans[len - i - 1] = res[i];
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
