#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wl)
{
    unordered_set<string> wordList(wl.begin(), wl.end());

    if (startWord == targetWord)
    {
        return 0;
    }
    if (wordList.find(targetWord) == wordList.end())
    {
        return 0;
    }

    queue<string> q;
    q.push(startWord);
    int ladderLen = 1;

    while (!q.empty())
    {
        int currSize = q.size();

        for (int i = 0; i < currSize; i++)
        {
            string currWord = q.front();
            q.pop();

            for (int j = 0; j < currWord.length(); j++)
            {
                char originalChar = currWord[j];

                for (char c = 'a'; c <= 'z'; c++)
                {
                    currWord[j] = c;

                    if (currWord == targetWord)
                    {
                        return ladderLen + 1;
                    }

                    if (wordList.find(currWord) != wordList.end())
                    {
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