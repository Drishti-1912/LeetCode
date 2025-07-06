class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        for(i=0;i<j;i++){
            swap(s[i],s[j]);
            j--;
        }
    }
};