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
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), ans = 0;
        vector<int> ss(n + 1, 0);
        for (int i = 0; i <= n - K; ++i){
            int res = (ss[i] - ss[max(i - K + 1, 0)] + A[i]) % 2;
            if(!res){
                ans++;
                ss[i + 1]++;
            }
            ss[i + 1] += ss[i];
        }
        for (int i = n - K + 1; i < n; ++i){
            int res = (ss[i] - ss[max(i - K + 1, 0)] + A[i]) % 2;
            if(!res) return -1;
            ss[i + 1] = ss[i];
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
