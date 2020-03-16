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
    stack<string> st;
public:
    bool isValid(string code) {
        string cdata_l = "[CDATA[", cdata_r = "]]>";
        int l = code.length();
        for (int i = 0; i < l; ){
            if (code[i] == '<'){
                // 处理标签（可能）
                if (i == l - 1) return false;
                int nxt = code[i + 1];
                if (nxt == '!'){
                    // CDATA
                    if (st.empty()) return false;
                    // 确认了在标签内部
                    bool flag1 = true;
                    for (int j = 0; j < 7; ++j)
                        if (i + 2 + j == l || cdata_l[j] != code[i + 2 + j])
                            return false;
                    // 确认了左边是 CDATA
                    int pos = code.find(cdata_r, i + 9);
                    if (pos < 0) return false;
                    // 确认了有结尾
                    i = pos + 3;
                }else if (nxt == '/'){
                    // 闭合
                    int tmp = i + 2; 
                    while (tmp < l && code[tmp] != '>'){
                        if (!isupper(code[tmp])) return false;
                        ++tmp;
                    }
                    if (tmp == l || tmp - i - 2 < 1 || tmp - i - 2 > 9) return false;
                    // 确认了有结尾
                    if (st.empty() || code.substr(i + 2, tmp - i - 2) != st.top())
                        return false;
                    st.pop();
                    // 处理完了一对标签
                    i = tmp + 1;
                }else {
                    // 普通标签
                    int tmp = i + 1;
                    while (tmp < l && code[tmp] != '>'){
                        if (!isupper(code[tmp])) return false;
                        ++tmp;
                    }
                    if (tmp == l || tmp - i - 1 < 1 || tmp - i - 1 > 9) return false;
                    if (st.empty() && i != 0) return false;
                    // 仍然被包围，加入到目前栈中
                    st.push(code.substr(i + 1, tmp - i - 1));
                    i = tmp + 1;
                }
            }else {
                // 处理一般的字符
                if (st.empty()) return false;
                ++i;
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};
Solution sol;
void init(){
    string a = "<A><![CDATA[</A>]]123></A>";
    cout << sol.isValid(a) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
