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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0, n = points.size();
        vector<int> tmp;
        auto sqr = [](int x){
            return x * x;
        };
        for (int i = 0; i < n; ++i){
            tmp.clear();
            for (int j = 0; j < i; ++j)
                tmp.push_back(sqr(points[i][0] - points[j][0]) + sqr(points[i][1] - points[j][1]));
            for (int j = i + 1; j < n; ++j)
                tmp.push_back(sqr(points[i][0] - points[j][0]) + sqr(points[i][1] - points[j][1]));
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < n - 1; ){
                int j = i;
                while(j < n - 1 && tmp[i] == tmp[j])
                    ++j;
                ans += (j - i) * (j - i - 1);
                i = j;
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
