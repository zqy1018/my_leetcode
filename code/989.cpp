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
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        int n = A.size(), i, x = 0;
        for (i = n - 1; i >= 0 && K; --i, K /= 10){
            x += A[i] + K % 10;
            ans.push_back(x % 10), x /= 10;
        }
        for (; i >= 0; --i)
            x += A[i], ans.push_back(x % 10), x /= 10;
        while(K)
            x += K % 10, ans.push_back(x % 10), x /= 10, K /= 10;
        if(x) ans.push_back(x);
        while(ans.size() > 1 && ans.back() == 0) ans.pop_back();
        reverse(ans.begin(), ans.end());
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
