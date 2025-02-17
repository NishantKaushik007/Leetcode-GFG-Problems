class Solution {
public:
    void solve(string& tiles,string curr,unordered_set<string>& st,vector<bool>& used)
    {
        st.insert(curr);
        for(int i=0;i<tiles.length();i++)
        {
            if(!used[i])
            {
                used[i]=true;
                solve(tiles,curr+tiles[i],st,used);
                used[i]=false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string>st;
        vector<bool>used(tiles.size(),false);
        solve(tiles,"",st,used);
        return st.size()-1;
    }
};