

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
    int f[3005], id[3005];
public:
    int pileBox(vector<vector<int>>& box) {
        int n = box.size();
        for (int i = 0; i < n; ++i)
            id[i] = i;
        sort(id, id + n, [&](int i, int j){
            if (box[i][0] == box[j][0]){
                if (box[i][1] == box[j][1])
                    return box[i][2] < box[j][2];
                return box[i][1] < box[j][1];
            }
            return box[i][0] < box[j][0];
        });
        //for (int i = 0; i < n; ++i)
        //    cout << box[id[i]] ;
        int ans = 0;
        for (int i = 0; i < n; ++i){
            f[i] = box[id[i]][2];
            for (int j = 0; j < i; ++j)
                if (box[id[j]][0] < box[id[i]][0] && box[id[j]][1] < box[id[i]][1] && box[id[j]][2] < box[id[i]][2])
                    f[i] = max(f[i], f[j] + box[id[i]][2]);
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
Solution sol;
void init(){
    vector<vector<int> > vec{{10, 9, 8}, {7, 9, 7}, {9, 7, 9}, {9, 7, 9}, {7, 7, 10}, {7, 9, 10}, {7, 8, 10}, {10, 8, 8}, {8, 9, 7}, {7, 9, 10}, {10, 10, 8}, {7, 8, 8}, {9, 9, 9}, {9, 8, 10}, {10, 10, 8}, {10, 9, 10}, {9, 8, 8}, {10, 9, 8}, {7, 8, 9}, {7, 9, 7}, {10, 10, 8}, {9, 7, 9}, {7, 9, 10}, {8, 8, 7}, {7, 8, 7}, {7, 10, 9}, {9, 8, 7}, {9, 9, 7}, {10, 10, 7}, {7, 9, 10}, {10, 10, 8}, {10, 7, 10}, {9, 7, 9}, {10, 9, 7}, {10, 7, 8}, {8, 10, 8}, {10, 7, 9}, {8, 8, 7}, {10, 9, 10}, {9, 10, 10}, {10, 10, 9}, {8, 10, 8}, {9, 7, 7}, {8, 7, 9}, {7, 10, 8}, {10, 10, 8}, {10, 10, 7}, {7, 10, 8}, {7, 8, 10}, {10, 9, 9}, {9, 8, 9}, {9, 10, 10}, {7, 9, 10}};
    cout << sol.pileBox(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
