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
    bool canTransform(string start, string end) {
        int n = start.size(), m = end.size();
        for (int i = 0, j = 0; i < n && j < m; ++i, ++j){
            while(i < n && start[i] == 'X') ++i;
            while(j < m && end[j] == 'X') ++j;
            if(i == n || j == m) {
                if(i == n && j == m) break;
                return false;
            }else{
                if(start[i] != end[j]) return false;
                else{
                    if(start[i] == 'R' && i > j) return false;
                    if(start[i] == 'L' && i < j) return false;
                }
            }
        }
        return true;
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
