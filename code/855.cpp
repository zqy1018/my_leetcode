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

class ExamRoom {
private:
    set<int> nums;
    set<pair<int, int> > diff;  // 保存了两个人之间的距离
    int siz, cap;
public:
    
    ExamRoom(int N) {
        siz = 0, cap = N;
    }
    
    int seat() {
        int ans;
        if (!siz) {
            nums.insert(0);
            ans = 0;
        }else if (siz == 1){
            int mini = *(nums.begin());
            if (mini >= cap - 1 - mini) {
                nums.insert(0);
                diff.insert(make_pair(-(mini >> 1), 0));
                ans = 0;
            }else {
                nums.insert(cap - 1);
                diff.insert(make_pair(-((cap - 1 - mini) >> 1), mini));
                ans = cap - 1;
            }
        }else {
            int dis = 0, mini = *(nums.begin()), maxi = *(nums.rbegin());
            dis = max(dis, mini);
            dis = max(dis, cap - 1 - maxi);
            pair<int, int> dis1 = *(diff.begin());
            dis = max(dis, -dis1.first);
            if (dis == mini){
                nums.insert(0);
                diff.insert(make_pair(-(mini >> 1), 0));
                ans = 0;
            }else if (dis == -dis1.first){
                int id = -dis1.first + dis1.second;
                int succ = *(nums.upper_bound(dis1.second));
                nums.insert(id);
                diff.erase(diff.begin());
                diff.insert(make_pair(-((id - dis1.second) >> 1), dis1.second));
                diff.insert(make_pair(-((succ - id) >> 1), id));
                ans = id;
            }else{
                nums.insert(cap - 1);
                diff.insert(make_pair(-((cap - 1 - maxi) >> 1), maxi));
                ans = cap - 1;
            }
        }
        ++siz;
        return ans;
    }
    
    void leave(int p) {
        set<int>::iterator it = nums.find(p);
        int pred = -1, succ = cap;
        if (p != *(nums.begin())){
            --it, pred = *it;
            diff.erase(make_pair(-((p - pred) >> 1), pred));
            ++it;
        }
        if (p != *(nums.rbegin())){
            ++it, succ = *it;
            diff.erase(make_pair(-((succ - p) >> 1), p));
            --it;
        }
        if (pred >= 0 && succ < cap)
            diff.insert(make_pair(-((succ - pred) >> 1), pred));
        nums.erase(it);
        --siz;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
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
