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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        sort(barcodes.begin(), barcodes.end());
        int n = barcodes.size();
        vector<int> ans(n, 0);
        int cur = 0;

        int flag = -1, hf = (n + 1) >> 1;
        for (int i = 0; i + hf <= n; ++i){
            if(barcodes[i] == barcodes[i + hf - 1]){
                flag = i;
                break;
            }
        }
        if(flag >= 0){
            int t = flag;
            for (int i = 0; i < n; i += 2){
                ans[i] = barcodes[flag++];
            }
            cur = 1;
            for (int i = 0; i < t; ++i)
                ans[cur] = barcodes[i], cur += 2;
            for (int i = flag; i < n; ++i)
                ans[cur] = barcodes[i], cur += 2;
            return ans;
        }

        for (int i = 0; i < n; i += 2)
            ans[i] = barcodes[cur++];
        for (int i = 1; i < n; i += 2)
            ans[i] = barcodes[cur++];
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
