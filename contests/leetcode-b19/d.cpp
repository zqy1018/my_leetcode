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
    int dis[50005];
    unordered_map<int, vector<int>> mp;
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        memset(dis, 0x3f, sizeof(dis));
        dis[0] = 0;
        for (int i = 0; i < n; ++i){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()){
            int h = q.front();
            q.pop();
            if (h - 1 >= 0 && h - 1 < n){
                if (dis[h - 1] > dis[h] + 1)
                    dis[h - 1] = dis[h] + 1, 
                    q.push(h - 1);
            }
            if (h + 1 >= 0 && h + 1 < n){
                if (dis[h + 1] > dis[h] + 1)
                    dis[h + 1] = dis[h] + 1, 
                    q.push(h + 1);
            }
            vector<int>& vc = mp[arr[h]];
            int t = vc.size();
            for (int i = 0; i < t; ++i){
                int v = vc[i];
                if (dis[v] > dis[h] + 1){
                    dis[v] = dis[h] + 1;
                    q.push(v);
                }
            }
            vc.clear();
        }
        return dis[n - 1];
    }
};
Solution sol;
void init(){
    vector<int> vec{11,22,7,7,7,7,7,7,7,22,13};
    cout << sol.minJumps(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
