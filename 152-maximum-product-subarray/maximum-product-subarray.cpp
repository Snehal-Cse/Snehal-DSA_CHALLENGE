class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
        long long leftProduct = 1;
        long long rightProduct = 1;
        long long ans = nums[0];

        for (int i = 0; i < n; i++) {
            // If any of leftProduct or rightProduct become 0 or less than minimum integer value, then update it to 1
            leftProduct = (leftProduct == 0 || leftProduct < INT_MIN) ? 1 : leftProduct;
            rightProduct = (rightProduct == 0 || rightProduct < INT_MIN) ? 1 : rightProduct;

            // Prefix product
            leftProduct *= nums[i];

            // Suffix product
            rightProduct *= nums[n - 1 - i];

            ans = max(ans, max(leftProduct, rightProduct));
        }

        return static_cast<int>(ans);
        }
};