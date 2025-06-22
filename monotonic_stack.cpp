// monotonic stack is applied to optimzely find the next or prev,greater or smaller elment in o(n) from brute force o(n^2)
//6,4,3,10,12,15,4 try a dry run u will understand

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;  // store indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}


vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;  // store indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}


// nse and pse in 1 loop
    int largestRectangleArea(vector<int>& heights,int &maxi) {
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                int element=st.top();st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int area=heights[element]*(nse-pse-1);
                maxi=max(maxi,area);
            }
                st.push(i);
        }
        while(!st.empty()){
            int element=st.top();st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            int area=heights[element]*(nse-pse-1);
            maxi=max(maxi,area);
        }
        return maxi;
    }
