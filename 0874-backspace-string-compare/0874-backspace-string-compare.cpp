class Solution {
public:
    string process(string str){
      string new_str="";
        int hash_count=0;

        for(int i=str.size()-1; i>=0; i--){
            //keep cnt of backspace char
            if(str[i] == '#'){
                hash_count++;
            }
            //if hashset>0 decrement hash_cnt and skip char
            else if(hash_count>0){
                hash_count--;
            }else{
                //if no backspace, just insert at beg
                new_str.insert(new_str.begin(),str[i]);
            }
        }
    return new_str;
    }

    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
      
};