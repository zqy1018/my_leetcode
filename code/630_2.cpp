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
    int id[10005];
    priority_queue<int> pq;
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size(), maxd = 0;
        for (int i = 0; i < n; ++i)
            id[i] = i, maxd = max(maxd, courses[i][1]);
        sort(id, id + n, [&](int i, int j){
            if (courses[i][1] == courses[j][1]) return courses[i][0] < courses[j][0];
            return courses[i][1] < courses[j][1];
        });
        
        int tot = courses[id[0]][0];
        pq.push(courses[id[0]][0]);
        for (int i = 1; i < n; ++i){
            int ddl = courses[id[i]][1], lst = courses[id[i]][0];
            if (lst + tot <= ddl)
                pq.push(lst), tot += lst;
            else if (!pq.empty() && pq.top() > lst){
                tot -= pq.top(), pq.pop();
                pq.push(lst), tot += lst;
            }
        }
        return pq.size();
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
