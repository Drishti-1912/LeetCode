class Solution {
public:
    int compress(vector<char>& chars) {
        int read=0;
        int write=0;
        int n=chars.size();
        while(read<n){
            char curr=chars[read];
            int cnt=0;
            while(read<n && chars[read]==curr){
                cnt++;
                read++;
            }
            chars[write]=curr;  //curr char assigned
            write++;

            if(cnt>1){
                string count_str=to_string(cnt);

                for(char ch : count_str){
                    chars[write]=ch;
                    write++;
                }
            }

        }
        return write;
    }
};