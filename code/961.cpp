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
    int repeatedNTimes(vector<int>& A) {
        int n = A.size();
        bitset<10000> bt;
        for (int i = 0; i < n; ++i){
            if(bt.test(A[i]))
                return A[i];
            else 
                bt.set(A[i]);
        }
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
