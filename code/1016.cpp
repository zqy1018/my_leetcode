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
    bool queryString(string S, int N) {
        int k = 1, n = S.length();
        while (k <= n && n - k + 1 >= (1 << k))
            ++k;
        if (n - k + 1 < N - (1 << k >> 1))
            return false;
        int left = N;
        unordered_set<int> st;
        st.insert(0);
        for (int i = 0; N >= (1 << i) && i < n; ++i){
            int t = (1 << i) - 1, lst = 0;
            for (int j = 0; j <= i; ++j)
                lst = (lst << 1 | (S[j] - '0'));
            for (int j = 0; j + i + 1 < n; ++j){
                if (!st.count(lst) && lst <= N)
                    st.insert(lst), --left;
                lst &= t, lst = (lst << 1 | (S[j + i + 1] - '0'));
            }
            if (!st.count(lst) && lst <= N)
                st.insert(lst), --left;
        }
        return left == 0;
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
