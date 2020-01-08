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
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        heights.push_back(0);
        int n = heights.size();
        vector<int> id, w;
        for (int i = 0; i < n; ++i){
            int curw = 0;
            while(!id.empty() && heights[id.back()] >= heights[i]){
                curw += w.back();
                ans = max(ans, curw * heights[id.back()]);
                id.pop_back(), w.pop_back();
            }
            id.push_back(i), w.push_back(curw + 1);
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
