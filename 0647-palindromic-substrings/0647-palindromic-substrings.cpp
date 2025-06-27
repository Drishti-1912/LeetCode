class Solution {
public:
    int countPal(string s,int left,int right){
        int cnt=0;
        while(left>=0 && right<s.size()){
            if(s[left]==s[right]){
                cnt++;
                left--;
                right++;
            }else{
                break;
            }
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            cnt+=countPal(s,i,i);
            cnt+=countPal(s,i,i+1);
        }
    return cnt;
    }
};