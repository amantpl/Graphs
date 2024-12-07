class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        set<string> st(wordList.begin(),wordList.end());
        
        if(st.find(endWord)==st.end()){
            return 0;
        }

        vector<char> alpha;
        for(char i='a';i<='z';i++){
            alpha.push_back(i);
        }
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        if(st.find(beginWord)!=st.end()){
            st.erase(beginWord);
        }

        int ans=0;

        while(!q.empty()){
            auto it=q.front();
            string word=it.first;
            int level=it.second;
            q.pop();

            if(word==endWord){
                ans=level;
            }

            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(auto it1:alpha){
                    word[i]=it1;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }

                word[i]=ch;
            }


        }

        return ans;
        
    }
};