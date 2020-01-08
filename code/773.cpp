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
    int slidingPuzzle(vector<vector<int>>& board) {
        int cnt1 = 0, a[6], b[6], tot = 0;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j])
                    a[tot++] = board[i][j];
        for (int i = 0; i < 5; ++i)
            for (int j = i + 1; j < 5; ++j)
                if (a[i] > a[j]) ++cnt1;
        if (cnt1 & 1) return -1;

        tot = 0;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                a[tot++] = board[i][j];

        auto pack = [](int *a){ return a[0] * 100000 + a[1] * 10000 + a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5]; };
        auto unpack = [](int x, int *a){ 
            int tot = 5;
            while (tot >= 0)
                a[tot--] = x % 10, x /= 10;
        };

        unordered_map<int, int> mp;
        queue<int> q;
        int cd = pack(a);
        q.push(cd), mp[cd] = 0;
        for (; ; ){
            int t = q.front(), step = mp[t];
            if (t == 123450) return step;
            q.pop();
            unpack(t, a);
            int pos = 0;
            while (a[pos] != 0) ++pos;

            if (pos != 0 && pos != 3) {
                swap(a[pos], a[pos - 1]);
                t = pack(a);
                if (!mp.count(t))
                    mp[t] = step + 1, q.push(t);
                swap(a[pos], a[pos - 1]);
            }
            if (pos != 2 && pos != 5) {
                swap(a[pos], a[pos + 1]);
                t = pack(a);
                if (!mp.count(t))
                    mp[t] = step + 1, q.push(t);
                swap(a[pos], a[pos + 1]);
            }
            if (pos <= 2) {
                swap(a[pos], a[pos + 3]);
                t = pack(a);
                if (!mp.count(t))
                    mp[t] = step + 1, q.push(t);
                swap(a[pos], a[pos + 3]);
            }else {
                swap(a[pos], a[pos - 3]);
                t = pack(a);
                if (!mp.count(t))
                    mp[t] = step + 1, q.push(t);
                swap(a[pos], a[pos - 3]);
            }
        }
        return 0;
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
