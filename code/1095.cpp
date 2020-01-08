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

class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (r > l){
            int mid1 = (l + r) >> 1;
            int mid2 = (mid1 + r + 1) >> 1;
            int a1 = mountainArr.get(mid1), a2 = mountainArr.get(mid2);
            if (a1 <= a2)
                l = mid1 + 1;
            else r = mid2 - 1;
        }
        int l1 = 0, r1 = l;
        while (l1 < r1){
            int mid = (l1 + r1 + 1) >> 1;
            if (mountainArr.get(mid) > target)
                r1 = mid - 1;
            else l1 = mid;
        }
        if (mountainArr.get(l1) == target) return l1;
        l1 = l + 1, r1 = n - 1;
        while (l1 < r1){
            int mid = (l1 + r1 + 1) >> 1;
            if (mountainArr.get(mid) < target)
                r1 = mid - 1;
            else l1 = mid;
        }
        if (mountainArr.get(l1) == target) return l1;
        return -1;
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
