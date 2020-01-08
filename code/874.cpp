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

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int> > mp;
        for (int i = 0; i < obstacles.size(); ++i){
            mp.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }
        int st = 0, x = 0, y = 0;
        int ans = 0;
        for (int i = 0; i < commands.size(); ++i){
            if (commands[i] == -1) st = (st == 3 ? 0: st + 1);
            else if (commands[i] == -2) st = (st == 0 ? 3: st - 1);
            else{
                pair<int, int> tmp(x, y);
                for (int j = 0; j < commands[i]; ++j){
                    tmp.first += dx[st], tmp.second += dy[st];
                    if (mp.count(tmp)) {
                        tmp.first -= dx[st], tmp.second -= dy[st];
                        break;
                    }else{
                        x += dx[st], y += dy[st];
                        ans = max(ans, x * x + y * y);
                    }
                }
            }
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
