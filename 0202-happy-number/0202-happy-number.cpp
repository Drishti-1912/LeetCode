class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> usedInteger;
        while(true){
            int sum=0;
            int temp=n; //to extract digits from temp, preserving n
            while(temp!=0){
                int digit=temp%10;
                sum+= digit*digit;
                temp = temp/10;
            }
            if (sum==1) return true;

            if(usedInteger.count(sum)) return false;
            usedInteger.insert(sum);
            n=sum;
        }
    }
};