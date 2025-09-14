class Solution {
public:
    string tolower(string s){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string , string>m;
        vector<string>ans;
        set<char>vovels;
        vovels.insert('a');
        vovels.insert('e');
        vovels.insert('i');
        vovels.insert('o');
        vovels.insert('u');

        for(auto word : wordlist){
            m[word] = word;
            if(m.find(tolower(word)+"_") == m.end()){
                m[tolower(word)+"_"] = word;
            }
            string s = tolower(word);

            for(int i=0 ; i<s.length() ; i++){
                if(vovels.find(s[i]) != vovels.end()){
                    s[i] = '*';
                }
            }

            if(m.find(tolower(s)) == m.end()){
                m[tolower(s)] = word;
            }
        }

        for(auto q : queries){
            string maskedVovels = tolower(q);
            for(int i=0 ; i<maskedVovels.length() ; i++){
                if(vovels.find(maskedVovels[i]) != vovels.end()){
                    maskedVovels[i] = '*';
                }
            }
            if(m.find(q) != m.end()){
                ans.push_back(q);
            }
            else if(m.find(tolower(q)+"_") != m.end()){
                ans.push_back(m[tolower(q)+"_"]);
            }
            else if(m.find(maskedVovels) != m.end()){
                ans.push_back(m[maskedVovels]);
            }
            else{
                ans.push_back("");
            }
        }

        return ans;
    }
};