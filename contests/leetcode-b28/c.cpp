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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}
class Solution {
    unordered_map<int, int> mp;
    int f[100005];
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum = 0;
        mp[0] = 0;
        int n = arr.size(), ans = 0x3f3f3f3f;
        memset(f, 0x3f, sizeof(f));
        for (int i = 1; i <= n; ++i){
            sum += arr[i - 1];
            int gp = sum - target;
            f[i] = f[i - 1];
            if (mp.count(gp)){
                int pos = mp[gp];
                f[i] = min(f[i], i - pos);
                ans = min(ans, i - pos + f[pos]);
            }
            mp[sum] = i;
        }
        return ans == 0x3f3f3f3f ? -1: ans;
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
