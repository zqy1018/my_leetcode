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
    unordered_map<int, int> mp[1005], mp2[1005]; 
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (1ll * A[i] - A[j] > INT_MAX || 1ll * A[i] - A[j] < INT_MIN)
                    continue;
                if (!mp2[i].count(A[i] - A[j]))
                    mp2[i][A[i] - A[j]] = 0;
                if (!mp[i].count(A[i] - A[j]))
                    mp[i][A[i] - A[j]] = 0;
                ++mp2[i][A[i] - A[j]];

                if (mp2[j].count(A[i] - A[j]))
                    mp[i][A[i] - A[j]] += mp2[j][A[i] - A[j]]; 
                if (mp[j].count(A[i] - A[j]))
                    mp[i][A[i] - A[j]] += mp[j][A[i] - A[j]]; 
            }
            for (auto& p: mp[i])
                ans += p.second;
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
