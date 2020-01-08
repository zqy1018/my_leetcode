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
    int longestOnes(vector<int>& A, int K) {
        int n = A.size(), ans = 0;
        for (int i = 0, j = -1, cnt = 0; i < n; ++i){
            while(j < n - 1 && cnt < K)
                ++j, cnt += 1 - A[j];
            while(j < n - 1 && A[j + 1] == 1)
                ++j;
            ans = max(ans, j - i + 1);
            if(j < i) j = i;
            if(!A[i]) cnt--;
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
