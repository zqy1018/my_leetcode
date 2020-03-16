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
    vector<int> to[1005];
    int dis[1005], du[1005];
    queue<int> q;
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        for (int i = 0; i < n; ++i){
            int j = i - 1; 
            while (j >= 0 && i - j <= d && arr[i] > arr[j])
                to[i].push_back(j), ++du[j], --j;
            j = i + 1;
            while (j < n && j - i <= d && arr[i] > arr[j])
                to[i].push_back(j), ++du[j], ++j;
        }
        for (int i = 0; i < n; ++i)
            if (!du[i]) dis[i] = 1, q.push(i);
        while (!q.empty()){
            int h = q.front();
            q.pop();
            for (int x: to[h]){
                --du[x];
                dis[x] = max(dis[x], dis[h] + 1);
                if (!du[x]) q.push(x);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dis[i]);
        return ans;
    }
};
Solution sol;
void init(){
    vector<int> arr{7,6,5,4,3,2,1};
    cout << sol.maxJumps(arr, 1);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
