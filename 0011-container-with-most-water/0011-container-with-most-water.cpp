class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int i=0,j=height.size()-1; //Two pointer
        while(i<j){
            int currentArea=min(height[i],height[j]) * (j-i);
            maxArea=max(maxArea,currentArea);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};