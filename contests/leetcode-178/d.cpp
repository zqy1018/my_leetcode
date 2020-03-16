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

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
class Solution {
    int n, m;
    int dis[105][105];
    priority_queue<pair<int, pair<int, int> > > pq;
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dis, 0x3f, sizeof(dis));
        dis[0][0] = 0;
        pq.push(make_pair(0, make_pair(0, 0)));
        for (int i = 1; i <= n * m; ++i){
            while (!pq.empty()){
                if (dis[pq.top().second.first][pq.top().second.second] < -pq.top().first)
                    pq.pop();
                else
                    break;
            }
            int x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            for (int j = 0; j < 4; ++j){
                int cx = x + dx[j], cy = y + dy[j];
                if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                    continue;
                int ww = ((j + 1 != grid[x][y]) ? 1: 0);
                if (dis[cx][cy] > dis[x][y] + ww)
                    dis[cx][cy] = dis[x][y] + ww, 
                    pq.push(make_pair(-dis[cx][cy], make_pair(cx, cy)));
            }
        }
        return dis[n - 1][m - 1];
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
