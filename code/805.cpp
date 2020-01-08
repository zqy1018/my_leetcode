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
    bool splitArraySameAverage(vector<int>& A) {90
        int n = A.size(), sum = 0;
        if(n <= 1) return false;
        for (int i: A)
            sum += i;
        vector<vector<bool> > f((n >> 1) + 1, vector<bool>(1 + (n >> 1) * sum / n, 0));
        f[0][0] = true;
        for (int i = 0; i < n; ++i){
            for (int j = (n >> 1); j >= 1; --j)
                for (int k = (n >> 1) * sum / n; k >= A[i]; --k){
                    if(f[j - 1][k - A[i]])
                        f[j][k] = true;
                }
        }
        for (int i = (n >> 1); i >= 1; --i){
            if(i * sum % n) continue;
            int targ = i * sum / n;
            if(f[i][targ]) return true;
        }
        return false;
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
