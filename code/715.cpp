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

class RangeModule {
    pair<int, int> vec[1005], tmp[1005];
    int cnt_vec, cnt_tmp;
    void show(){
        for (int i = 0; i < cnt_vec; ++i){
            cout << "[" << vec[i].first << ", " << vec[i].second << "]" << endl;
        }
    }
public:
    RangeModule() {
        cnt_vec = 0;
    }
    
    void addRange(int left, int right) {
        cnt_tmp = 0;
        int flag = -1;
        for (int i = 0; i < cnt_vec; ++i){
            int l = vec[i].first, r = vec[i].second;
            if (r < left) 
                tmp[cnt_tmp++] = vec[i];
            else if (r == left){
                left = l;
            }else if (r <= right){
                left = min(left, l);
            }else {
                if (l <= left) {
                    flag = i;
                    break;
                }
                if (l <= right) right = r;
                else {
                    tmp[cnt_tmp++] = make_pair(left, right);
                    flag = i;
                    break;
                }
            }
        }
        if (flag < 0) tmp[cnt_tmp++] = make_pair(left, right);
        else {
            for (int i = flag; i < cnt_vec; ++i)
                tmp[cnt_tmp++] = vec[i];
        }
        for (int i = 0; i < cnt_tmp; ++i)
            vec[i] = tmp[i];
        cnt_vec = cnt_tmp;
    }
    
    bool queryRange(int left, int right) {
        int l = 0, r = cnt_vec;
        while (r > l){
            int mid = (l + r) >> 1;
            if (vec[mid].second < right) l = mid + 1;
            else r = mid; 
        }
        return l < cnt_vec && vec[l].first <= left;
    }
    
    void removeRange(int left, int right) {
        cnt_tmp = 0;
        int flag = cnt_vec;
        for (int i = 0; i < cnt_vec; ++i){
            int l = vec[i].first, r = vec[i].second;
            if (r <= left) 
                tmp[cnt_tmp++] = vec[i];
            else if (r <= right){
                if (l < left) 
                    tmp[cnt_tmp++] = make_pair(l, left);
            }else {
                if (l < right){
                    if (l < left)
                        tmp[cnt_tmp++] = make_pair(l, left);
                    tmp[cnt_tmp++] = make_pair(right, r);
                    flag = i + 1;
                }else {
                    flag = i;   
                }
                break;
            }
        }
        for (int i = flag; i < cnt_vec; ++i)
            tmp[cnt_tmp++] = vec[i];
        for (int i = 0; i < cnt_tmp; ++i)
            vec[i] = tmp[i];
        cnt_vec = cnt_tmp;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
void init(){
    RangeModule a;
    a.addRange(10, 20);
    a.removeRange(14, 16);
    cout << a.queryRange(10, 14) << endl;
    cout << a.queryRange(13, 15) << endl;
    cout << a.queryRange(16, 17) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
