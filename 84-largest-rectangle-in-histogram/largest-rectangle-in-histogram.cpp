#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
private:
    vector<int> nextSmaller(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n, n); // Initialize with n to handle the edge case
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n, -1); // Initialize with -1 to handle the edge case
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmaller(heights, n);
        vector<int> prev = prevSmaller(heights, n);
        int area = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = next[i] - prev[i] - 1;
            int newArea = height * width;
            area = max(area, newArea);
        }
        return area;
    }
};
