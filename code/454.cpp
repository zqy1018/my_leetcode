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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> aa, bb;
        int n = A.size(), ans = 0;
        if(!n) return 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                aa.push_back(A[i] + B[j]), bb.push_back(C[i] + D[j]);
        sort(bb.begin(), bb.end());
        for (int i = 0; i < n * n; ++i)
            ans += upper_bound(bb.begin(), bb.end(), -aa[i]) - lower_bound(bb.begin(), bb.end(), -aa[i]); 
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
