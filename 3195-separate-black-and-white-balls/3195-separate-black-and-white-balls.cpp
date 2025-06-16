class Solution {
public:
    long long minimumSteps(string s) {
        int i=0;
        long long cnt=0;
        for(int j=0;j<s.size();j++){
            if (s[j]=='0'){
                swap(s[i],s[j]);
                cnt+=j-i;
                i++;
            }
        }
    return cnt;
    }
};