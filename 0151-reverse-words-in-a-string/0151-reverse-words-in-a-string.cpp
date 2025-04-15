class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(!word.empty()){
                    st.push(word);
                    word="";
                }
            continue;
            }
            else{
                word+=s[i];
            }
        }
        if(!word.empty()){
            st.push(word);
        }

        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
            if(!st.empty()){
            res+=" ";
            }
        }
        return res;
    }
};