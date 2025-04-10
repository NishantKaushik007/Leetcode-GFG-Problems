class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words;
        for(string s:wordList)
        words.insert(s);
        queue<pair<int,string>>q;
        q.push({0,beginWord});
        words.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().second;
            int t=q.front().first;
            q.pop();
            if(word==endWord)
            return t+1;
            for(int i=0;i<word.length();i++)
            {
                string original=word;
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(words.find(word)!=words.end())
                    {
                        q.push({t+1,word});
                        words.erase(word);
                    }
                }
                word=original;
            }
        }
        return 0;
    }
};