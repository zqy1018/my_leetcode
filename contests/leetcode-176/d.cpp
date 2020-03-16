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
    priority_queue<long long> pq;
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0, n = target.size();
        if (n == 1) return target[0] == 1;
        for (int i = 0; i < n; ++i)
            pq.push(target[i]), sum += target[i];
        for (; sum > n; ){
            long long t = pq.top();
            pq.pop();
            long long others = sum - t;
            if (t <= others)
                return false;
            long long se = pq.top();
            if (se == 1) return (t - 1) % others == 0;
            long long mini = (t - se) / others + 1;
            t -= mini * others;
            sum -= mini * others;
            if (t <= 0) return false;
            pq.push(t);
        }        
        return sum == n;
    }
};
Solution sol;
void init(){
    vector<int> vec{9, 3, 5};
    sol.isPossible(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
