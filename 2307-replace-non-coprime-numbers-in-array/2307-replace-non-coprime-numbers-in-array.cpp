class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for(int& num : nums) {
            int cur = num, GCD;
            while(!res.empty()) {
                if((GCD = gcd(res.back(), cur)) <= 1) break;
                cur *= res.back() / GCD;
                res.pop_back();
            }
            res.push_back(cur);
        }
        return res;
    }
};