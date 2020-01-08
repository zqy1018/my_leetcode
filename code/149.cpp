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
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<long double, int> mp;
        int ans = 0;
        for (int i = 0; i < points.size(); ++i){
            mp.clear();
            int vect = 0, self = 1, maxi = 0;
            for (int j = i + 1; j < points.size(); ++j){
                if (points[j][0] == points[i][0])
                    if (points[j][1] == points[i][1]) self++;
                    else vect++;
                else{
                    long double k = (long double) (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    if (!mp.count(k)) mp[k] = 1, maxi = max(maxi, 1);
                    else ++mp[k], maxi = max(maxi, mp[k]);
                }
            }
            maxi = max(maxi, vect) + self;
            ans = max(ans, maxi);
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
