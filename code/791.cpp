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
    string customSortString(string S, string T) {
        vector<int> prio(26, -1);
        int i = 0;
        for (char c: S)
            prio[c - 'a'] = i, i++;
        auto cmp = [&prio](char a, char b){
            return prio[a - 'a'] < prio[b - 'a'];
        };
        sort(T.begin(), T.end(), cmp);
        return T;
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
