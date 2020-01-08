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

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), m = wall[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < wall[i].size(); ++j)
                wall[i][j] += wall[i][j - 1];
        auto cmp = [&wall](pair<int, int> pi, pair<int, int> pj){
            return wall[pi.first][pi.second] > wall[pj.first][pj.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i)
            pq.push(make_pair(i, 0));
        int ans = n;
        while (!pq.empty()){
            pair<int, int> pt = pq.top();
            pq.pop();
            int cnt = 1, val = wall[pt.first][pt.second];
            while (!pq.empty()){
                if (wall[pq.top().first][pq.top().second] != val) break;
                int id = pq.top().first, pos = pq.top().second;
                pq.pop();
                if (pos != wall[id].size() - 1)
                    pq.push(make_pair(id, pos + 1));
                ++cnt;
            }
            if (pt.second != wall[pt.first].size() - 1)
                pq.push(make_pair(pt.first, pt.second + 1));
            if (val < wall[0][m - 1])
                ans = min(ans, n - cnt);
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
