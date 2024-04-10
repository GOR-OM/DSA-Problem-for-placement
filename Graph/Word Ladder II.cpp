#include<bits/stdc++.h>
using namespace std ;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) { 
    unordered_set<string> wl (wordList.begin(), wordList.end());
        vector<vector<string>>ans;
        if(beginWord == endWord){
            return ans;
        }
        if(wl.find(endWord)== wl.end()){
            return ans;
        }

        queue<vector<string>>q; 
        q.push({beginWord});
        while (!q.empty()){
            int currentSize = q.size();
            bool flag = false;
            string current = q.front().back();
            for(int i=0;i<currentSize; i++){
                string cur = q.front().back();
                vector<string> curr = q.front();
                q.pop();
                for(int j=0;j<cur.size();j++){
                    char original = cur[j];
                    for(char c='a'; c<'z'; c++){
                        cur[j] = c;

                        if(cur==endWord){
                            curr.push_back(cur);
                            q.push(curr);
                            flag= true;
                        }
                        if(wl.find(cur)!=wl.end()){
                            curr.push_back(cur);
                            q.push(curr);
                        }

                    }
                    cur[j]=original;
                }

            }
            wl.erase(current);
            if(flag==true)break;
        }
        while(!q.empty()){
            if(q.front().back()==endWord){
                ans.push_back(q.front());
                q.pop();
            }
        }
        return ans;

    }


int wordLadderLength(string startWord, string targetWord, vector<string>& wl) {
    unordered_set<string> wordList(wl.begin(), wl.end());

    if (startWord == targetWord) {
        return 0;
    }
    if (wordList.find(targetWord) == wordList.end()) {
        return 0;
    }

    queue<string> q;
    q.push(startWord);
    int ladderLen = 1;

    while (!q.empty()) {
        int currSize = q.size();

        for (int i = 0; i < currSize; i++) {
            string currWord = q.front();
            q.pop();

            for (int j = 0; j < currWord.length(); j++) {
                char originalChar = currWord[j];

                for (char c = 'a'; c <= 'z'; c++) {
                    currWord[j] = c;

                    if (currWord == targetWord) {
                        return ladderLen + 1;
                    }

                    if (wordList.find(currWord) != wordList.end()) {
                        q.push(currWord);
                        wordList.erase(currWord);
                    }
                }

                currWord[j] = originalChar;
            }
        }

        ladderLen++;
    }

    return 0;
}