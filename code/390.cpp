class Solution {
public:
    int dfs(int n, int o){
        if (n == 1) return 1;
        if (o == 1) return dfs(n >> 1, 0) << 1;
        else{
            if (n & 1) return dfs(n >> 1, 1) << 1;
            return (dfs(n >> 1, 1) << 1) - 1;
        }
    }
    int lastRemaining(int n) {
        return dfs(n, 1);
    }
};