class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(balance>0){
                result+=s[i];
                }

                balance++;     // Increase the balance for '('

                }else{
                    balance--;       // Decrease the balance for ')'

                // If balance is greater than 0, it means this ')' is not an
                // outermost parenthesis
                    if(balance>0){
                    result+=s[i];  // Add the character to the result  
                    }
                }
            }
        return result; 
    }
};