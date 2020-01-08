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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1), f1(n + 1, 0), f2(n + 1, 0);
        int ss = 0, maxi = -1, ans = 0;
        for (int i = 0; i < n; ++i)
            ss += nums[i], sum[i + 1] = ss;
        for (int i = 2 * k, lst = k; i <= n; ++i){
            f1[i] = lst;
            if(sum[i - k + 1] - sum[i + 1 - k - k] > sum[lst] - sum[lst - k])
                lst = i - k + 1;
        }
        for (int i = 3 * k, lst = k + k; i <= n; ++i){
            f2[i] = lst;
            if(sum[f1[i + 1 - k]] - sum[f1[i + 1 - k] - k] + sum[i + 1 - k] - sum[i + 1 - k - k] > 
                sum[f1[lst]] - sum[f1[lst] - k] + sum[lst] - sum[lst - k])
                lst = i - k + 1;
            if(sum[i] - sum[i - k] + sum[f2[i]] - sum[f2[i] - k] + sum[f1[f2[i]]] - sum[f1[f2[i]] - k] > maxi)
                maxi = sum[i] - sum[i - k] + sum[f2[i]] - sum[f2[i] - k] + sum[f1[f2[i]]] - sum[f1[f2[i]] - k], ans = i;
        }
        vector<int> rans;
        rans.push_back(f1[f2[ans]] - k);
        rans.push_back(f2[ans] - k);
        rans.push_back(ans - k);
        return rans;
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
