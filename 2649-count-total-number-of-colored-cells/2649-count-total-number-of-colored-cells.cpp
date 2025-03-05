class Solution {
public:
    long long coloredCells(int n) {
        long long numBlueCells = 1;
        int add=4;
        while(--n){
            numBlueCells += add;
            add += 4;
        }
        return numBlueCells;
    }
};