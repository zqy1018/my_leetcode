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
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = 0, cur = 0;
        while(cur < n && !seats[cur])
            ++cur;
        ans = max(ans, cur);
        int lst = cur;
        ++cur;
        while(cur < n){
            while(cur < n && !seats[cur])
                ++cur;
            if(cur == n) {
                ans = max(ans, n - 1 - lst);
                break;
            }
            ans = max(ans, (cur - lst) >> 1);
            lst = cur;
            ++cur;
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
