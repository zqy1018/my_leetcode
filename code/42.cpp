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
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n, 0), r(n, 0);
        int ans = 0;
        for (int i = 1; i < n; ++i)
            l[i] = max(l[i - 1], height[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            r[i] = max(r[i + 1], height[i + 1]), 
            ans += max(0, min(l[i], r[i]) - height[i]);
        
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
