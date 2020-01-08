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

int id[3005];
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            id[i] = i;
        sort(id, id + n, [&intervals](int i, int j){
            return intervals[i][0] == intervals[j][0] ? intervals[i][1] < intervals[j][1]:
                intervals[i][0] < intervals[j][0];
        });
        int ans = 0;
        for (int i = 0; i < n; ){
            int j = i + 1;
            int l = intervals[id[i]][0], r = intervals[id[i]][1];
            while (j < n){
                int ll = intervals[id[j]][0], rr = intervals[id[j]][1];
                ll = max(l, ll), rr = min(r, rr);
                if (rr - ll < 1)
                    break;
                l = ll, r = rr;
                ++j;
            }
            
            i = j;
        }
        
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
