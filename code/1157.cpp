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

class MajorityChecker {
    int n, bsize;
    int sum[205][20005], lis[205], tot;
    int cnt[20005];
    vector<int>& a;
public:
    MajorityChecker(vector<int>& arr) : a(arr){
        memset(sum, 0, sizeof(sum)) ;
        n = arr.size();
        bsize = static_cast<int>(floor(n * 2) + 0.5);
        memset(cnt, 0, sizeof(cnt));
        for (int x: arr)    
            ++cnt[x];
        tot = 0;
        for (int i = 1; i <= 20000; ++i){
            if (cnt[i] > 2 * n / bsize){
                lis[++tot] = i;
                for (int j = 1; j <= n; ++j)
                    sum[tot][j] = sum[tot][j - 1] + (arr[j - 1] == i ? 1: 0);
            }
        }
    }
    
    int query(int left, int right, int threshold) {
        if (right - left + 1 <= bsize){
            int x = 0, ccnt = 0;
            for (int i = left; i <= right; ++i) {
                if (!ccnt) ccnt = 1, x = a[i];
                else ccnt = (x == a[i] ? ccnt + 1: ccnt - 1);
            }
            ccnt = 0;
            for (int i = left; i <= right; ++i) 
                if (x == a[i]) ++ccnt;
            return (ccnt >= threshold ? x: -1);
        }else {
            for (int i = 1; i <= tot; ++i)  {
                if (sum[i][right + 1] - sum[i][left] >= threshold)
                    return lis[i];
            }
            return -1;
        }
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
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
