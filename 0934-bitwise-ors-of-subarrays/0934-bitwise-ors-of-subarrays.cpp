class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> subset;
        set<int> resSet;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            set<int> st;
            for(auto &ele: subset) {
                st.insert(ele | arr[i]);
            }
            st.insert(arr[i]);
            for(auto &ele: st) {
                resSet.insert(ele);
            }
            swap(st , subset);
        }
        return resSet.size();
    }
};