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
    bool isBoomerang(vector<vector<int>>& points) {
        for (int i = 0; i < 3; ++i)
            for (int j = i + 1; j < 3; ++j)
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    return false;
        return !((points[2][0] - points[0][0]) * (points[1][1] - points[0][1]) == (points[1][0] - points[0][0]) * (points[2][1] - points[0][1]));
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
