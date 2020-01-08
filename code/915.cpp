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
    int partitionDisjoint(vector<int>& A) {
        int n = A.size(), maxi = -1;
        vector<int> mini(n + 1, 0);
        mini[n] = 1000001;
        for (int i = n - 1; i >= 0; --i)
            mini[i] = min(A[i], mini[i + 1]);
        for (int i = 0; i < n; ++i){
            maxi = max(maxi, A[i]);
            if(maxi <= mini[i + 1])
                return i + 1;
        }
        return n;
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
