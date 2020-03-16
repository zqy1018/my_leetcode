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

class Robot {
  public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
};
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
class Solution {
    set<pair<int, int>> st;
    inline void stepback(Robot& robot){
        robot.turnLeft(), robot.turnLeft(), robot.move(), 
        robot.turnLeft(), robot.turnLeft();
    }
    void dfs(Robot& robot, int x, int y, int d){
        // 认为：进入和退出时的朝向一致

        robot.clean();          // 先打扫自己这里
        for (int i = 0; i < 4; ++i) {
            int dd = (i + d) % 4;
            int cx = x + dx[dd], cy = y + dy[dd];
            if (!st.count(make_pair(cx, cy))) {
                bool res = robot.move();
                if (res){
                    st.insert(make_pair(cx, cy));
                    dfs(robot, cx, cy, dd);
                    stepback(robot);
                }
            }
            robot.turnLeft();
        }
    }
public:
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
};
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
