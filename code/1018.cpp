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
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int x = 0;
        vector<bool> ans;
        for (int i: A){
            x = x << 1 | i;
            if(x == 5) x = 0, ans.push_back(true);
            else {
                ans.push_back(false);
                x %= 5;
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
