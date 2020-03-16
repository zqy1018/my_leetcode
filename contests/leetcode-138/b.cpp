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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int outside = 0, ans = 0;
        for (int i = X; i < n; ++i)
            if(!grumpy[i]) outside += customers[i];
        for (int i = 0; i < X; ++i)
            outside += customers[i];
        for (int i = X - 1; i < n; ){
            ans = max(ans, outside);
            ++i;
            if(i == n) break;
            if(grumpy[i]) outside += customers[i];
            if(grumpy[i - X]) outside -= customers[i - X];
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
