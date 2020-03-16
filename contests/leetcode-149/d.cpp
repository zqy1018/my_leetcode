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

class MajorityChecker {
public:
    vector<int> ar, tmp;
    MajorityChecker(vector<int>& arr) {
        ar = arr;
        tmp = vector<int>(arr.size(), 0);
    }
    
    int query(int left, int right, int threshold) {
        int cnt = right - left + 1;
        unordered_map<int, int> mp;
        for (int i = left; i <= right; ++i) {
            if (!mp.count(ar[i])) mp[ar[i]] = 1;
            else ++mp[ar[i]];
            if (mp[ar[i]] >= threshold) return ar[i];
            if (mp.size() > cnt - threshold + 1) return -1;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
void init(){
    vector<int> aa{1, 1, 2, 2, 1, 1};
    MajorityChecker mc(aa);
    cout << mc.query(2, 3, 2) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
