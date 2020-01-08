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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

class Solution {
public:
    int primePalindrome(int N) {
        if (N <= 2) return 2;
        if (N <= 3) return 3;
        if (N <= 5) return 5;
        if (N <= 7) return 7;
        int ans = 2147483647;

        auto check = [](int x){
            for (int i = 2; i * i <= x; ++i)
                if (x % i == 0) return false;
            return true;
        };

        auto build_ = [](int x){
            int t = 0, tmp = x;
            while(tmp)
                t = t * 10 + tmp % 10, tmp /= 10, x *= 10;
            return t + x;
        };
        auto build = [](int x){
            int t = 0, tmp = x;
            while(tmp)
                t = t * 10 + tmp % 10, tmp /= 10, x *= 10;
            if (t % 5 == 0 || (t & 1) == 0) return -1;
            return t + x;
        };
        auto bs = [&build_](int x){
            int l = 1, r = 9999; 
            while (r > l){
                int mid = (l + r) >> 1;
                if (build_(mid) < x) l = mid + 1;
                else r = mid;
            }  
            return l;
        };
        for (int i = bs(N); i < 10000; ++i){
            int res1 = build(i);
            if (res1 < 0) continue;
            if (check(res1)) {
                ans = res1; break;
            }
        }

        auto build2_ = [](int x, int app){
            int t1 = 0, t2 = 1, tmp = x;
            x *= 10;
            while(tmp)
                t1 = t1 * 10 + tmp % 10, t2 *= 10, tmp /= 10, x *= 10;
            return t1 + x;
        };
        auto build2 = [](int x, int app, int& apper){
            int t1 = 0, t2 = 1, tmp = x;
            x *= 10;
            while(tmp)
                t1 = t1 * 10 + tmp % 10, t2 *= 10, tmp /= 10, x *= 10;
            if (t1 % 5 == 0 || (t1 & 1) == 0) return -1;
            apper = t2;
            return t1 + x;
        };
        auto bs2 = [&build2_](int x){
            int l = 1, r = 9999, t; 
            while (r > l){
                int mid = (l + r) >> 1;
                if (build2_(mid, 9) < x) l = mid + 1;
                else r = mid;
            }  
            return l;
        };
        
        for (int i = bs2(N); i < 10000; ++i){
            int app;
            int res = build2(i, 0, app);
            if (res < 0) continue;
            if (res >= ans) break;
            for (int j = 0; j < 10; ++j, res += app){
                if (res < N) continue;
                if (check(res)) return res;
            }
        }
        return ans;
    }
};
Solution sol;
void init(){
    
}
void solve(){
	auto check = [](int x){
            for (int i = 2; i * i <= x; ++i)
                if (x % i == 0) return false;
            return true;
        };

        auto build_ = [](int x){
            int t = 0, tmp = x;
            while(tmp)
                t = t * 10 + tmp % 10, tmp /= 10, x *= 10;
            return t + x;
        };
        auto build = [](int x){
            int t = 0, tmp = x;
            while(tmp)
                t = t * 10 + tmp % 10, tmp /= 10, x *= 10;
            if (t % 5 == 0 || (t & 1) == 0) return -1;
            return t + x;
        };
        for (int i = 1; i < 10000; ++i){
            int res1 = build(i);
            if (res1 < 0) continue;
            if (check(res1)) {
                cout << res1 << endl;
            }
        }
}
int main(){
	init();
	solve();
	return 0;
}
