class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        long long zeroCount = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                zeroCount++;  // zeros to the right of current position
            } else {
                steps += zeroCount;  // each '1' must move past all zeros on the right
            }
        }

        return steps;
    }
};

