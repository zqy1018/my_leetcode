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

ostream& operator << (ostream& os, const vector<int>& vec){
    for (int x: vec)
        os << x << " ";
    os << endl;
    return os;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
    void dfs( TreeNode* root, string& ans ){
        if (root == NULL) {
            ans.push_back(' ');
            ans.push_back('#');
            return ;
        }
        ans.push_back(' ');
        ans += to_string( root->val );
        dfs( root->left, ans );
        dfs( root->right, ans );
    }
    // Encodes a tree to a single string.
    string serialize2(TreeNode* root) {
        string ans("");
        dfs( root, ans );
        return ans;
    }
    pair<TreeNode*, int> dfs2( string& data, int l ){
        ++l;
        if ( data[l] == '#' ) return make_pair( ( TreeNode* ) NULL, l + 1 );
        int x = 0, flag = 1;
        if ( data[l] == '-' ) flag = -1, ++l;
        while ( data[l] != ' ' )
            x = x * 10 + data[l] - '0', ++l;
        x = x * flag;
        TreeNode* root = new TreeNode(x);
        pair<TreeNode*, int> res = dfs2 ( data, l );
        root->left = res.first, l = res.second;
        res = dfs2 ( data, l );
        root->right = res.first, l = res.second;
        return make_pair( root, l );
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize2(string data) {
        return dfs2( data, 0 ).first;
    }
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == nullptr) return nullptr;
        TreeNode *cur = new TreeNode(root->val), *tmp = cur;
        int n = root->children.size();
        if (!n) return cur;
        cur->left = encode(root->children[0]), cur = cur->left;
        for (int i = 1; i < n; ++i)
            cur->right = encode(root->children[i]), cur = cur->right;
        return tmp;
    }
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (root == nullptr) return nullptr;
        Node *cur = new Node(root->val);
        root = root->left;
        while (root != nullptr)
            cur->children.push_back(decode(root)), 
            root = root->right;
        return cur;
    }
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        return serialize2(encode(root));
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        return decode(deserialize2(data));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
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
