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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size(), ans = 0;
        stack<int> st, w;
        vector<int> h(m + 1, 0);
        for (int i = 0, cur = 0; i < m; ++i){
            if(matrix[0][i] == '1') h[i] = 1, cur++, ans = max(ans, cur);
            else cur = 0, h[i] = 0;
        }
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if(matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            while(!st.empty())
                st.pop(), w.pop();
            for (int j = 0; j <= m; ++j){
                int curw = 0;
                while(!st.empty() && st.top() >= h[j])
                    curw += w.top(), ans = max(ans, curw * st.top()), st.pop(), w.pop();
                w.push(curw + 1), st.push(h[j]);
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
