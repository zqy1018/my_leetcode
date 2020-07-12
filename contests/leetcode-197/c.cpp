#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

const int M = 1000000007;
inline int lowbit(int x){
    return x & (-x);
}
inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
    vector<pair<int, double> > G[10005];
    priority_queue<pair<double, int>, vector<pair<double, int> > , greater< pair<double, int> > > pq; 
    bool vis[10005];
    double dis[10005]; 
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int m = edges.size();
        for (int i = 0; i < m; ++i){
            double d = log(succProb[i]);
            int u = edges[i][0], v = edges[i][1];
            G[u].push_back(make_pair(v, d));
            G[v].push_back(make_pair(u, d));
        }
        pq.push(make_pair(0, start));
        for (; ; ){
            while (!pq.empty()){
                if (vis[pq.top().second]) pq.pop();
                else break;
            }
            if (pq.empty()) break;
            int h = pq.top().second;
            double dd = pq.top().first;
            pq.pop();
            vis[h] = true;
            for (auto& x: G[h]){
                int v = x.first;
                double w = x.second;
                if (dd + w < dis[v])
                    dis[v] = dd + w, 
                    pq.push(make_pair(v, dis[v]));
            }
        }
        if (!vis[end]) return 0;
        return exp(-dis[end]);
    }
};
Solution sol;

int main(){

    return 0;
}
