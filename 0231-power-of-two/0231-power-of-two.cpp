class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x;
        if(n<=0) return false;
        for(int x=0;x<=31;x++){
        if(n==pow(2,x)) return true;
        }
        return false;
    }
};