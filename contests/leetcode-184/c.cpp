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
public:
    string entityParser(string text) {
        string ans;
        int n = text.length();
        for (int i = 0; i < n; ++i){
            if (text[i] == '&'){
                int j = i;
                while (j < n && text[j] != ';')
                    ++j;
                bool flag = false;
                if (j - i == 5){
                    ans.push_back('/'), flag = true;
                }else if (j - i == 3){
                    ans.push_back('&'), flag = true;
                }else if (j - i == 4){
                    if (text[i + 1] == 'q') ans.push_back('\"'), flag = true;
                    if (text[i + 1] == 'a') ans.push_back('\''), flag = true;
                }else {
                    if (text[i + 1] == 'g') ans.push_back('>'), flag = true;
                    if (text[i + 1] == 'l') ans.push_back('<'), flag = true;
                }
                if (!flag){
                    for (int t = i; t <= j; ++t)
                        ans.push_back(text[t]);
                }
                i = j;
            }else ans.push_back(text[i]);
        }
        return ans;
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
