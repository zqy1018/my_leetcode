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
    set<int> st;
    int kEmptySlots(vector<int>& bulbs, int K) {
        int n = bulbs.size();
        for (int i = 0; i < n - K; ++i){
            int x = bulbs[i];
            st.insert(x);
            auto p = st.find(x);
            auto prev = p, next = p;
            if (p != st.begin()){
                --prev;
                if (x - *prev == K + 1) return i + 1;
            }
            ++next;
            if (next != st.end()){
                if (*next - x == K + 1) return i + 1;
            }
        }
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
