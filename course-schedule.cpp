#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>


using namespace std;




class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // <1, 0> : first 0 then 1
        vector<vector<int> > nexts(numCourses, vector<int>());
        vector<int> ins(numCourses, 0);
        queue<int> heads;
        for(vector<pair<int, int> >::iterator itr = prerequisites.begin(); itr != prerequisites.end(); itr++) {
            pair<int, int> p = *itr;
            ins[p.first]++;
            nexts[p.second].push_back(p.first);
        }
        for (int i = 0; i < numCourses; i++) {
            if (ins[i] == 0)
                heads.push(i);
        }
        vector<int> res = bfs(nexts, heads, ins);
        return (res.size() == numCourses);
    }

    vector<int> bfs(vector<vector<int> >& nexts, queue<int>& heads, vector<int>& ins) {
        vector<int> res;

        while(!heads.empty()) {
            int h = heads.front();
            res.push_back(h);
            heads.pop();
            vector<int> next = nexts[h];
            for (vector<int>::iterator itr = next.begin(); itr != next.end(); itr++) {
                int n = *itr;
                if (--ins[n] == 0) {
                    heads.push(n);
                }
            }
        }
        return move(res);
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > nexts(numCourses, vector<int>());
        for(vector<pair<int, int> >::iterator itr = prerequisites.begin(); itr != prerequisites.end(); itr++) {
            pair<int, int> p = *itr;
            nexts[p.first].push_back(p.second);
        }
        return dfs_wrapper(nexts, numCourses);
    }

    vector<int> dfs_wrapper(vector<vector<int> >& nexts, int num) {
        vector<int> res;
        vector<int> visit(num, 0);
        bool circle = false;
        for (int i = 0; i < num; i++) {
            if (!visit[i] && !circle)
                dfs(nexts, res, visit, circle, i);
        }
        if (circle) return vector<int>();
        else return move(res);
    }

    void dfs(vector<vector<int> >& nexts, vector<int>& res, vector<int>& visit, bool &circle, int i) {
        if (circle) return;
        vector<int> next = nexts[i];
        // 解决环的问题，正在深度遍历的节点不能被再次访问
        // 1 访问， 0 未访问 -1 访问中
        visit[i] = -1;
        for (vector<int>::iterator itr = next.begin(); itr != next.end(); itr++) {
            if (visit[*itr] != 1) {
                if (visit[*itr] == 0)
                    dfs(nexts, res, visit, circle, *itr);
                else {
                    circle = 1;
                    return;
                }

            }
        }
        visit[i] = 1;
        res.push_back(i);
    }

};