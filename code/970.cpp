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
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        if(x > y) swap(x, y);
        if(x == 1){
            if(y == 1 && bound >= 2) ans.push_back(2);
            else {
                for (int j = 1; j + 1 <= bound; j *= y)
                    ans.push_back(j + 1);
            }
            return ans;
        }
        for (int i = 1; i < bound; i *= x)
            for (int j = 1; i + j <= bound; j *= y)
                ans.push_back(i + j);
        sort(ans.begin(), ans.end());
        auto newend = unique(ans.begin(), ans.end());
        ans.erase(newend, ans.end());
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
