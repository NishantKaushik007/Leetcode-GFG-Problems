class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordDict(wordList.begin(),wordList.end());
        queue<pair<int,string>>q;
        q.push({0,beginWord});
        wordDict.erase(beginWord);
        while(!q.empty())
        {
            int steps=q.front().first;
            string word=q.front().second;
            q.pop();
            if(word==endWord)
            return steps+1;
            for(int i=0;i<word.length();i++)
            {
                char original=word[i];
                for(char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if(wordDict.find(word)!=wordDict.end())
                    {
                        q.push({steps+1,word});
                        wordDict.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};