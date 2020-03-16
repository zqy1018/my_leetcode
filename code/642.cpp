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

class AutocompleteSystem {
    int ids[205], len;
    bool is_first;
    string ss;
    vector<string>& sentences_ref;
    vector<int>& times_ref;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) :
        sentences_ref(sentences), times_ref(times){
        is_first = true;
    }
    
    vector<string> input(char c) {
        vector<string> ans;
        if (is_first){
            if (c == '#') return ans;
            is_first = false;
            len = 0;
            ss.push_back(c);
            int n = sentences_ref.size();
            for (int i = 0; i < n; ++i){
                if (sentences_ref[i][0] != c) continue;
                ids[len++] = i;
            }
            sort(ids, ids + len, [&](int i, int j){
                if (times_ref[i] == times_ref[j]) return sentences_ref[i] < sentences_ref[j];
                return times_ref[i] > times_ref[j];
            });
            for (int i = 0; i < min(3, len); ++i)
                ans.push_back(sentences_ref[ids[i]]);
            return ans;
        }
        if (c == '#'){
            int n = sentences_ref.size();
            bool flag = false;
            for (int i = 0; i < n; ++i)
                if (sentences_ref[i] == ss){
                    ++times_ref[i];
                    flag = true;
                    break;
                }
            if (!flag){
                sentences_ref.push_back(ss);
                times_ref.push_back(1);
            }
            ss.clear();
            is_first = true;
            return ans;
        }
        int newlen = 0, ll = ss.length();
        ss.push_back(c);
        for (int i = 0; i < len; ++i)
            if (sentences_ref[ids[i]][ll] == c)
                ids[newlen++] = ids[i];
        len = newlen;
        for (int i = 0; i < min(3, len); ++i)
            ans.push_back(sentences_ref[ids[i]]);
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
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
