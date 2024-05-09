class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        stack<int> st;
        st.push(0);

        int area = 0;

        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] >= heights[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int left = st.top();
                        int right = i;
                        area = max(area, heights[mid] * (right - left - 1));
                    }
                }
                st.push(i);
            }
        }
        return area;
    }
};