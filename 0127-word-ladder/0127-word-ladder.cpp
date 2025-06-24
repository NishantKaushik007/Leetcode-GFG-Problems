class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<int,string>>q;
        q.push({0,beginWord});
        st.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().second;
            int time=q.front().first;
            q.pop();
            if(word==endWord)
            return time+1;
            for(int i=0;i<word.length();i++)
            {
                string original=word;
                for(char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if(st.count(word))
                    {
                        q.push({time+1,word});
                        st.erase(word);
                    }
                }
                word=original;
            }
        }
        return 0;
    }
};