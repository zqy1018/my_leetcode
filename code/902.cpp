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
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> vec;
        if (N == 1000000000) --N;
        for (string& s: D) vec.push_back(stoi(s));
        int ws = 0, ten = 1;
        for (int tmp = N, QQ = 1; tmp > 0; tmp /= 10) ++ws, ten *= 10;
        int ans = 0, Q = vec.size(), QQ = 1;
        for (int i = 0; i < ws; ++i)
            ans += QQ, QQ *= Q;
        --ans, QQ /= Q, ten /= 10;

        for (; ten > 0; ){
            int cur = 0;
            while (cur < Q && vec[cur] < N / ten)
                ++cur;
            ans += cur * QQ;
            if (!cur || cur == Q || vec[cur] > N / ten)
                break;
            QQ /= Q, N %= ten, ten /= 10;
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
