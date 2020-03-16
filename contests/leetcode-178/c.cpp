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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> vec, ll;
    int nn;
    bool dfs(TreeNode* cur){
        if (cur == NULL) return false;
        vec.push_back(cur->val);
        bool res = false;
        res = (res || dfs(cur->left));
        res = (res || dfs(cur->right));
        bool flag = true;
        if (vec.size() >= nn){
            int nnn = vec.size();
            for (int j = nnn - nn, p = 0; j < nnn; ++j, ++p){
                if (vec[j] != ll[p])    {
                    flag = false;
                    break;
                }
            }
        }
        res = (res || flag);
        vec.pop_back();
        return res;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        nn= 0;
        ListNode* tmp  = head;
        while (tmp != NULL)
            ll.push_back(tmp->val), 
            tmp = tmp->next, ++nn;
        return dfs(root);
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
