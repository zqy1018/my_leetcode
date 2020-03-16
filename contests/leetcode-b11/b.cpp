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

pair<int, int> p1[10005], p2[10005];
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> ans;
        int n1 = slots1.size(), n2 = slots2.size();
        for (int i = 0; i < n1; ++i)    
            p1[i].first = slots1[i][0], p1[i].second = slots1[i][1];
        for (int i = 0; i < n2; ++i)    
            p2[i].first = slots2[i][0], p2[i].second = slots2[i][1];
        sort(p1, p1 + n1);
        sort(p2, p2 + n2);
        int cur = 0;
        for (int i = 0; i < n1; ++i){
            while (cur < n2 && p2[cur].second <= p1[i].first)
                ++cur;
            if (cur == n2) break;
            if (p1[i].second <= p2[cur].first)
                continue;
            if (p2[cur].first <= p1[i].first){
                if (min(p2[cur].second, p1[i].second) - p2[cur].first >= duration){
                    ans.push_back(p1[i].first);
                    ans.push_back(p1[i].first + duration);
                    return ans;
                }
            }else {
                if (min(p2[cur].second, p1[i].second) - p1[i].first >= duration){
                    ans.push_back(p2[cur].first);
                    ans.push_back(p2[cur].first + duration);
                    return ans;
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
