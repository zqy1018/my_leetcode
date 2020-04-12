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
    vector<int> p, tmp;
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        for (int i = 0; i < m; ++i)
            p.push_back(i + 1);
        vector<int> ans;
        for (int x: queries){
            int pos = 0;
            while (p[pos] != x) ++pos;
            ans.push_back(pos);
            tmp.clear();
            tmp.push_back(p[pos]);
            for (int i = 0; i < m; ++i)
                if (i != pos) tmp.push_back(p[i]);
            for (int i = 0; i < m; ++i)
                p[i] = tmp[i];
        }
        return ans;
    }
};
Solution sol;
void init(){
    vector<int> vec{7,5,5,8,3};
    cout << sol.processQueries(vec, 8)  ;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
