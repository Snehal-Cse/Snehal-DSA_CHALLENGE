class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int newArea = 0;
        int maxArea = -1e7;
        while(left<right){
            newArea = min(height[left], height[right])*(right-left);
            maxArea= max(maxArea, newArea);
            if(height[left]< height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};