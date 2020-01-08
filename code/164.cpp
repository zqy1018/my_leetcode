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
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
		int mini = INT_MAX, maxi = -1;
		for (int i = 0; i < n; ++i)	
			mini = min(mini, nums[i]), 
			maxi = max(maxi, nums[i]);

		vector<bool> vis(n, false);
        vector<int> mine(n, INT_MAX), maxe(n, -1);
		int bsize = max(1, (maxi - mini) / (n - 1));
		if (bsize * (n - 1) < (maxi - mini))
			++bsize;
		
        for (int i = 0; i < n; ++i)	{
			int bid = (nums[i] - mini) / bsize;
			vis[bid] = true;
			mine[bid] = min(mine[bid], nums[i]);
			maxe[bid] = max(maxe[bid], nums[i]);
		}
		int ans = 0, cur = 0;
		while (!vis[cur]) ++cur;
		for (; cur < n; )	{
			ans = max(ans, maxe[cur] - mine[cur]);
			int j = cur + 1;
			while (j < n && !vis[j])
				++j;
			if (j == n) break;
			ans = max(ans, mine[j] - maxe[cur]);
			cur = j;
		}
		return ans;
    }
};
Solution sol;
void init(){
	vector<int> vec{1, 10000000};
    cout << sol.maximumGap(vec);
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
