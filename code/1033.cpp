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
    vector<int> numMovesStones(int a, int b, int c) {
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        int mini = 2, maxi = c - a - 2;
        if(a == b - 1 && b == c - 1) mini = 0;
        else if (a == b - 1) mini--;
        else if(b == c - 1) mini--;
        else{
            if(b - a == 2 || c - b == 2) mini--;
        }
        return vector<int>{mini, maxi};
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
