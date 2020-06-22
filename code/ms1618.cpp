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
    bool m(string& s, int a, int b, int l){
        for (int i = 0; i < l; ++i)
            if (s[a + i] != s[b + i])
                return false;
        return true;
    }
public:
    bool patternMatching(string pattern, string value) {
        int lp = pattern.length(), lv = value.length();
        if (lp == 0) return lv == 0;
        int cnt0 = 0, cnt1 = 0;
        char bm = pattern[0];
        for (char c: pattern){
            if (c == bm) ++cnt0;
            else ++cnt1;
        }
        if (lv == 0) return cnt0 * cnt1 == 0;
        
        for (int i = 0; i <= lv / cnt0; ++i){
            if ((cnt1 != 0 && (lv - i * cnt0) % cnt1 != 0) ||
                (cnt1 == 0 && i * cnt0 != lv))
                continue;
            int l2 = (cnt1 == 0 ? 0: (lv - i * cnt0) / cnt1);
            bool flag = true;
            int ach0 = -1, ach1 = -1;
            for (int j = 0, t = 0; t < lp && flag; ++t){
                if (pattern[t] == bm){
                    if (ach0 == -1) ach0 = j;
                    else flag = flag && m(value, ach0, j, i);
                    j += i;
                }else {
                    if (ach1 == -1) ach1 = j;
                    else flag = flag && m(value, ach1, j, l2);
                    j += l2;
                }
            }
            if (flag && (ach0 == -1 || ach1 == -1 || i != l2 ||
                !m(value, ach0, ach1, i))) return true;
        }
        return false;
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
