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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int> > ans;
        int n = intervals.size();
        int l = toBeRemoved[0], r = toBeRemoved[1];
        for (int i = 0; i < n; ++i){
            int ll = intervals[i][0], rr = intervals[i][1];
            if (ll >= r || rr <= l)
                ans.push_back(intervals[i]);
            else if (l >= ll && r <= rr){
                vector<int> vec = intervals[i];
                vec[1] = l;
                ans.push_back(vec);
                vec[1] = intervals[i][1], vec[0] = r;
                ans.push_back(vec);
            }else {
                if (ll >= l && rr <= r){

                }else if (ll >= l){
                    intervals[i][0] = r;
                    ans.push_back(intervals[i]);
                }else if (rr <= r){
                    intervals[i][1] = l;
                    ans.push_back(intervals[i]);
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
