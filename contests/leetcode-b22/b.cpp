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
    int id[100005];
    bool vis[13];
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        for (int i = 0; i < m; ++i)
            id[i] = i;
        sort(id, id + m, [&](int i, int j){
            return reservedSeats[i][0] == reservedSeats[j][0] ? reservedSeats[i][1] < reservedSeats[j][1]: reservedSeats[i][0] < reservedSeats[j][0];
        });
        int ans = 0, tot = 0;
        for (int i = 0; i < m; ){
            int j = i;
            memset(vis, 0, sizeof(vis));
            while (j < m && reservedSeats[id[i]][0] == reservedSeats[id[j]][0])
                vis[reservedSeats[id[j]][1]] = true, ++j;
            bool f1 = true, f2 = true, f3 = true;
            for (int i = 2; i <= 5; ++i){
                if (vis[i]) f1 = false;
            }
            for (int i = 4; i <= 7; ++i){
                if (vis[i]) f2 = false;
            }
            for (int i = 6; i <= 9; ++i){
                if (vis[i]) f3 = false;
            }
            if (f1 && f3) ans += 2;
            else if (f1 || f2 || f3) ans += 1;
            ++tot;
            i = j;
        }
        ans += 2 * (n - tot);
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
