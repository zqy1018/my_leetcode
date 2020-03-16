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
    bool isRobotBounded(string instructions) {
        int jd = 0, x = 0, y = 0;
        int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
        for (char c: instructions){
            if(c == 'G') 
                x += dx[jd], y += dy[jd];
            if(c == 'L') jd = (jd - 1 + 4) % 4;
            if(c == 'R') jd = (jd + 1) % 4;
        }
        if(jd % 4 != 0) return true;
        if(!x && !y) return true;
        return false;
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
