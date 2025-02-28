class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return merge(buildings, 0, buildings.size() - 1);
    }

private:
    vector<vector<int>> merge(vector<vector<int>>& buildings, int lo, int hi) {
        vector<vector<int>> res;
        if (lo > hi) return res;
        if (lo == hi) {
            res.push_back({buildings[lo][0], buildings[lo][2]});
            res.push_back({buildings[lo][1], 0});
            return res;
        }

        int mid = lo + (hi - lo) / 2;
        vector<vector<int>> left = merge(buildings, lo, mid);
        vector<vector<int>> right = merge(buildings, mid + 1, hi);

        deque<vector<int>> lq(left.begin(), left.end());
        deque<vector<int>> rq(right.begin(), right.end());

        int leftH = 0, rightH = 0;
        while (!lq.empty() || !rq.empty()) {
            long x1 = lq.empty() ? LONG_MAX : lq.front()[0];
            long x2 = rq.empty() ? LONG_MAX : rq.front()[0];
            int x = 0;

            if (x1 < x2) {
                x = lq.front()[0];
                leftH = lq.front()[1];
                lq.pop_front();
            } else if (x1 > x2) {
                x = rq.front()[0];
                rightH = rq.front()[1];
                rq.pop_front();
            } else {
                x = lq.front()[0];
                leftH = lq.front()[1];
                rightH = rq.front()[1];
                lq.pop_front();
                rq.pop_front();
            }

            int h = max(leftH, rightH);
            if (res.empty() || h != res.back()[1]) {
                res.push_back({x, h});
            }
        }
        return res;
    }
};