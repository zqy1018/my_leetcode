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
    vector<int> bb;
    int lowbit(int x){
        return x & (-x);
    }
    void update(int k, int r, int n){
        while(k <= n)
            bb[k] = min(bb[k], r), k += lowbit(k);
    }
    int query(int k){
        int res = 0x3f3f3f3f;
        while(k)
            res = min(res, bb[k]), k -= lowbit(k);
        return res;
    }
    int jump(vector<int>& nums) {
        vector<pair<int, int> > nnums;
        vector<int> f;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            nnums.push_back(make_pair(-i - nums[i], i));
        sort(nnums.begin(), nnums.end());
        for (pair<int, int> pp: nnums)
            cout << pp.first << " " << pp.second << endl;
        f = vector<int>(n, 0x3f3f3f3f);
        bb = vector<int>(n + 1, 0x3f3f3f3f);
        {
            f[0] = 0;
            int iid = lower_bound(nnums.begin(), nnums.end(), make_pair(-nums[0], 0)) - nnums.begin();
            update(iid + 1, 0, n);
        }
        for (int i = 1; i < n; ++i){
            int id = upper_bound(nnums.begin(), nnums.end(), make_pair(-i, n)) - nnums.begin();
            f[i] = query(id) + 1;
            int iid = lower_bound(nnums.begin(), nnums.end(), make_pair(-i - nums[i], i)) - nnums.begin();
            update(iid + 1, f[i], n);
            cout << i << " " << id << " " << iid << endl;
        }
        return f[n - 1];
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
