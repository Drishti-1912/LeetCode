class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            //find total hours needed for each pile

            double hours=0;
            for(int p:piles){
                hours+=ceil((double)p / (double) mid );
            }
            if(hours == h){
                ans = mid;
                high = mid-1;
            }
            else if(hours<=h){
                ans = mid;
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
    return ans;
    }
};