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
    string getPermutation(int n, int k) {
        int fac = 1;
        for (int i = 2; i < n; ++i)
            fac *= i;
        vector<bool> used(n, false);
        string ans("");
        k--;
        for (int i = 0; i < n; ++i){
            int u = k / fac;
            k = k % fac;
            int res = 0;
            for (int cnt = 0; cnt < u || used[res]; ++res)
                if(!used[res]) cnt++;
            char cc = '0' + 1 + res;
            used[res] = true, ans.append(1, cc);
            if(i < n - 1) fac /= (n - i - 1);
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
