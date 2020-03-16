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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<pair<int, int> > vec;
        for (int i = 0; i < dominoes.size(); ++i){
            int fs = dominoes[i][0], sec = dominoes[i][1];
            if(fs >= sec) swap(fs, sec);
            vec.push_back(make_pair(fs, sec));
        }
        sort(vec.begin(), vec.end());
        int ans = 0;
        for (int i = 0; i < vec.size(); ){
            int j = i;
            while(j < vec.size() && vec[i] == vec[j])
                ++j;
            ans += ((j - i) * (j - i - 1)) >> 1;
            i = j;
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
