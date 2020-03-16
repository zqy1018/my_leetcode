

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

class MyCalendarThree {
    pair<pair<int, int>, int> vec[1005], tmp[1005];
    int cnt_vec, cnt_tmp, ans;
public:
    MyCalendarThree() {
        cnt_vec = ans = 0;
    }
    
    int book(int start, int end) {
        cnt_tmp = 0;
        int flag = -1;
        for (int i = 0; i < cnt_vec; ++i){
            int l = vec[i].first.first, r = vec[i].first.second;
            int kk = vec[i].second;
            if (r <= start) 
                tmp[cnt_tmp++] = vec[i];
            else if (r <= end){
                if (l < start){
                    tmp[cnt_tmp++] = make_pair(make_pair(l, start), kk);
                    tmp[cnt_tmp++] = make_pair(make_pair(start, r), kk + 1);
                }else {
                    if (l > start)
                        tmp[cnt_tmp++] = make_pair(make_pair(start, l), 1);
                    tmp[cnt_tmp++] = make_pair(make_pair(l, r), kk + 1);
                }
                if (r == end) {
                    flag = i + 1; 
                    break;
                }else start = r;
            }else {
                if (l >= end){
                    tmp[cnt_tmp++] = make_pair(make_pair(start, end), 1);
                    flag = i;
                    break;
                }

                if (l < start) 
                    tmp[cnt_tmp++] = make_pair(make_pair(l, start), kk);
                else if (l > start)
                    tmp[cnt_tmp++] = make_pair(make_pair(start, l), 1);
                
                tmp[cnt_tmp++] = make_pair(make_pair(min(start, l), end), kk + 1);
                tmp[cnt_tmp++] = make_pair(make_pair(end, r), kk);
                flag = i + 1;
                break;
            }
        }
        if (flag < 0) tmp[cnt_tmp++] = make_pair(make_pair(start, end), 1);
        else {
            for (int i = flag; i < cnt_vec; ++i)
                tmp[cnt_tmp++] = vec[i];
        }
        for (int i = 0; i < cnt_tmp; ++i)
            vec[i] = tmp[i], ans = max(ans, vec[i].second);
        cnt_vec = cnt_tmp;
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
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
