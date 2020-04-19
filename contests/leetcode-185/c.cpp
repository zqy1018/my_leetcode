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
    int at[10];
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int l = croakOfFrogs.length();
        memset(at, 0, sizeof(at));
        for (char c: croakOfFrogs){
            int cur;
            if (c == 'c') cur = 0;
            if (c == 'r') cur = 1;
            if (c == 'o') cur = 2;
            if (c == 'a') cur = 3;
            if (c == 'k') cur = 4;
            if (cur == 0){
                if (at[4] > 0)
                    --at[4];
                ++at[0];
            }else {
                if (!at[cur - 1]) return -1;
                --at[cur - 1], ++at[cur];
            }
        }
        for (int i = 0; i < 4; ++i)
            if (at[i] > 0)return -1;
        return at[4];
    }
};
Solution sol;
void init(){
    cout << sol.minNumberOfFrogs("croakcroa");
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
