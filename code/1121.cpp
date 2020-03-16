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

// 伪贪心
class Solution {
public:
    int cnt[100005];
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int tot = 0;
        priority_queue<pair<int, int> > pq;
        int mini = -1, cur = 1;
        for (int x: nums)
            ++cnt[x];
        while (cur <= 100000 && pq.size() < K){
            if (cnt[cur]) pq.push(make_pair(-cnt[cur], cur));
            if (pq.size() == K) mini = cur;
            ++cur;
        }
        if (pq.size() < K) return false;
        while (cur <= 100000){
            auto p = pq.top();
            int tt = -p.first - tot, id = p.second;
            pq.pop(), cnt[id] = 0;
            tot += tt;              // 抽取这么一个子序列
            while (!pq.empty() && pq.top().first == -tt){
                id = pq.top().second;
                cnt[id] = 0;
                pq.pop();
            }
            while (cur <= 100000 && pq.size() < K){
                if (cnt[cur]) pq.push(make_pair(-cnt[cur] - tot, cur));
                ++cur;
            }
        }
        int lft = -1;
        for (int i = 1; i <= 100000; ++i)   
            if (cnt[i]) {
                lft = i;
                break;
            }
        if (lft == -1) return true;
        return lft > mini;
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
