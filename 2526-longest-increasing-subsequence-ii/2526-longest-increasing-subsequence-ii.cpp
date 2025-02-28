
class SegmentTree {
private:
    vector<int> st;
    int n;

    void Update(int node, int beg, int end, int i, int value) {
        if (beg == end) {
            st[node] = max(st[node], value);
            return;
        }

        int mid = (beg + end) / 2;
        if (i <= mid) Update(2 * node, beg, mid, i, value);
        else Update(2 * node + 1, mid + 1, end, i, value);

        st[node] = max(st[2 * node], st[2 * node + 1]);
    }

    int Query(int node, int beg, int end, int i, int j) {
        if (end < i || beg > j) return 0;
        if (i <= beg && end <= j) return st[node];

        int mid = (beg + end) / 2;
        return max(Query(2 * node, beg, mid, i, j), Query(2 * node + 1, mid + 1, end, i, j));
    }

public:
    SegmentTree(int n) : n(n), st(4 * n, 0) {}

    void Update(int i, int value) {
        Update(1, 0, n - 1, i, value);
    }

    int Query(int i, int j) {
        return Query(1, 0, n - 1, i, j);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree tree(1e5 + 1);
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            int left = max(0, nums[i] - k);
            int right = nums[i] - 1;
            int dpValue = tree.Query(left, right) + 1;
            tree.Update(nums[i], dpValue);
            maxLength = max(maxLength, dpValue);
        }

        return maxLength;
    }
};
