// count frequencies in both basket1 and basket2, then checking for odd counts (which would make it impossible).

// Track extra elements from each basket.

// Build a list of mismatched items (those that need to be swapped).

// Compute the cost using the greedy approach.

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> basket1_count , basket2_count;

        // Count frequencies in basket1 and basket2 separately
        for(int element : basket1){
            basket1_count[element]++;
        }
        for(int element : basket2){
            basket2_count[element]++;
        }

        // For example:
        // Basket1: {1, 2, 2, 3}
        // Basket2: {2, 3, 3, 4}
        // Here, unique fruits are {1, 2, 3, 4}.
        // The total count of fruit 2 is 2 (basket1) + 1 (basket2) = 3.
        // To check if it's possible to evenly split fruits between the baskets (each fruit must have an even   total count).

        // Set to keep track of all unique fruits
        unordered_map<int, int> total_count;

        // Collect all unique fruits and their total counts
        for (const auto& p : basket1_count) total_count[p.first] += p.second;  
        for (const auto& p : basket2_count) total_count[p.first] += p.second;
        //p.first is the fruit ID (an integer representing a type of fruit).
        // p.second is the count of how many times that fruit appears.


        // Check if total count of each fruit is even (feasibility check)
        for (const auto& p : total_count) {
            if (p.second % 2 != 0) return -1; // impossible to split evenly
        }

        vector<int> extras;  //fruits that need to be swapped (from basket1's surplus)
        // Identify surplus fruits in basket1 that need to be swapped out
        for (const auto& p : total_count) {
            int fruit = p.first;
            int total = p.second;
            int half = total / 2;

            int count_b1 = basket1_count[fruit]; // 0 if not present
            if (count_b1 > half) {
                int surplus = count_b1 - half;
                for (int i = 0; i < surplus; ++i) {
                    extras.push_back(fruit);
                }
            }
        }
        //surplus form basket 2 also 
        for (const auto& p : total_count) {
            int fruit = p.first;
            int half = p.second / 2;

            int count_b2 = basket2_count[fruit];
            if (count_b2 > half) {
                int surplus = count_b2 - half;
                for (int i = 0; i < surplus; ++i) {
                    extras.push_back(fruit);
                }
            }
        }

        // If no extras, baskets are already equal
        if (extras.empty()) return 0;

        // Sort extras to consider cheapest fruits first
        sort(extras.begin(), extras.end());

        // Find the smallest fruit cost globally (in both baskets)
        int min_fruit = INT_MAX;
        for (int f : basket1) min_fruit = min(min_fruit, f);
        for (int f : basket2) min_fruit = min(min_fruit, f);

        long long total_cost = 0;
        int n = extras.size();

        // Only half the swaps are needed, since one swap fixes two mismatches
            // Choose cheaper cost:
            // direct swap cost = extras[i]
            // or indirect swap via smallest fruit = 2 * min_fruit
           for (int i = 0; i < n / 2; ++i) {
            total_cost += min(extras[i], 2 * min_fruit);
        }

        return total_cost;
    }
};