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
    int lst[100];
public:
    int findTheLongestSubstring(string s) {
        memset(lst, -1, sizeof(lst));
        int h = 0;
        lst[h] = 0;
        int ans = 0, cur = 0;
        for (char c: s){
            ++cur;
            if (c == 'a') h ^= (1 << 0);
            else if (c == 'e') h ^= (1 << 1);
            else if (c == 'i') h ^= (1 << 2);
            else if (c == 'o') h ^= (1 << 3);
            else if (c == 'u') h ^= (1 << 4);
            if (lst[h] >= 0) ans = max(ans, cur - lst[h]);
            else lst[h] = cur;
        }
        return ans;
    }
};
Solution sol;
void init(){
    string s("a");
    cout << sol.findTheLongestSubstring(s);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
