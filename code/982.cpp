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
    int countTriplets(vector<int>& A) {
        int n = A.size(), maxi = 1, ans = 0;
        vector<int> cnt(65536, 0);
        for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j) 
                cnt[A[i] & A[j]]++;
			while(maxi <= A[i]) maxi <<= 1;
		}
        for (int i = 0; i < n; ++i){
			for (int j = 0; j < maxi; ++j){
				if(A[i] & j) continue;
				ans += cnt[j];
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
