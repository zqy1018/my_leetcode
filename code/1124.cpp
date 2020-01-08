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
    int longestWPI(vector<int>& hours) {
        for (int &i: hours){
            if(i > 8) i = 1; else i = 0;
        }
        int ssm = 0;
        vector<pair<int, int> > vec;
        for (int i = 0; i < hours.size(); ++i){
            ssm += hours[i];
            vec.push_back(make_pair(2 * ssm - (i + 1), i + 1));
        }
        vec.push_back(make_pair(0, 0));
        sort(vec.begin(), vec.end());
        int mini = hours.size() + 1, ans = 0;
        for (int i = 0; i <= hours.size(); ){
            int j = i, tmpmini = mini, tmpmaxi = -1;
            while(j <= hours.size() && vec[i].first == vec[j].first) 
                tmpmini = min(tmpmini, vec[j].second), 
                tmpmaxi = max(tmpmaxi, vec[j].second), ++j;
            ans = max(ans, tmpmaxi - mini);
            mini = tmpmini, i = j;
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
