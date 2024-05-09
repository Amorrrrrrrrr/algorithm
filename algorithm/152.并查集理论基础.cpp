1. 并查集常用来解决连通性问题。(当我们需要判断两个元素是否在同一个集合里的时候，我们就要想到用并查集。)

2. 并查集主要有三个功能：
    - 寻找根节点
    - 将两个元素添加到一个集合中。
    - 判断两个元素在不在同一个集合

3. 代码模板：
int n = 1005;                                               /* n根据题目中节点数量而定，一般比节点数量大一点就好 */ 
vector<int> father = vector<int> (n, 0);

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}

// 并查集里寻根的过程
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);/* 路径压缩 */ 
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集
void join(int u, int v) {
    u = find(u);                                            /* 寻找u的根 */
    v = find(v);                                            /* 寻找v的根 */
    if (u == v) return;                                     /* 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回 */ 
    father[v] = u;
}