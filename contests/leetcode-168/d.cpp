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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool vis[1005];
bool opened[1005];
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        memset(vis, 0, sizeof(vis));
        memset(opened, 0, sizeof(opened));
        int n = status.size();
        queue<int> box;
        for (int x: initialBoxes){
            if (status[x]) box.push(x);
            vis[x] = true;     // 暂时获得
        }
        int ans = 0;
        while (!box.empty()){
            int h = box.front();
            box.pop();
            opened[h] = true;
            ans += candies[h]   ;
            for (int k: keys[h]){
                status[k] = 1;
                if (vis[k] && !opened[k]) box.push(k);
            }
            for (int x: containedBoxes[h]){
                vis[x] = true;
                if (status[x] && !opened[k]) box.push(x)    ;
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
