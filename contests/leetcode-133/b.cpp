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
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        auto c = [r0, c0](pair<int, int> &pp1, pair<int, int> &pp2) -> bool{
            int d1 = abs(pp1.first - r0) + abs(pp1.second - c0);
            int d2 = abs(pp2.first - r0) + abs(pp2.second - c0);
            return d1 < d2;
        };
        vector<pair<int, int> > vec;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                vec.push_back(make_pair(i, j));
        sort(vec.begin(), vec.end(), c);
        vector<vector<int> > ans;
        for (int i = 1; i < R * C; ++i){
            vector<int> aa;
            aa.push_back(vec[i].first);
            aa.push_back(vec[i].second);
            ans.push_back(aa);
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
