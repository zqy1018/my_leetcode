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
    int hIndex(vector<int>& citations) {
		int n = citations.size();
        if(!n) return 0;
        int l = 0, r = n - 1;
		while(l < r){
			int mid = (l + r) >> 1;
			if(citations[mid] >= n - mid)
				r = mid;
			else l = mid + 1;
		}
        if(!citations[n - 1]) l = n;
		return n - l;
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
