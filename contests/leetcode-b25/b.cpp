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
    int maxDiff(int num) {
        string s = to_string(num);
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < 10; ++i){
            for (int j = 0; j < 10; ++j){
                string t = s;
                for (char& c: t)
                    if (c == i + '0')   
                        c = j + '0';
                if (t[0] == '0') continue;
                int dd = stoi(t);
                if (dd == 0) continue;
                maxi = max(maxi, dd);
                mini = min(mini, dd);
            }
            
        }
        return maxi - mini;
    }
};
Solution sol;
void init(){
    cout << sol.maxDiff(9288)    ;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
