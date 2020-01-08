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
    string convert(string s, int numRows) {
        int len = s.size();
        numRows = min(numRows, len);
        if(numRows == 1)
            return s;
        vector<vector<char>> vec(len, vector<char>()); //初始层数，赋值
        for (int i = 0; i < len; ++i) 
	        vec[i] = vector<char>(len, 0);
        //construct the character matrix
        int lim = (len - 1) / (2 * numRows - 2) + 1; //upper bound
        for (int i = 0; i < lim; ++i){
            int j = i * (2 * numRows - 2);
            for (int k = 0; k < numRows && j < len; ++k, ++j)
                vec[k][i * (numRows - 1)] = s[j];
            for (int k = 1; k < numRows - 1 && j < len; ++k, ++j)
                vec[numRows - 1 - k][i * (numRows - 1) + k] = s[j];
        }
        string ans = "";
        for (int i = 0; i < numRows; ++i)
            for (int j = 0; j < lim * (numRows - 1); ++j)
                if(vec[i][j]) ans += vec[i][j];
        return ans;
    }
};
Solution sol;
void init(){
    
}
void solve(){
	cout << sol.convert("A", 2);
}
int main(){
	init();
	solve();
	return 0;
}
