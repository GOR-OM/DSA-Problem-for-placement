#include<bits/stdc++.h>
using namespace std;


struct Node{
    Node* links[26];
    bool flag = false;
    bool containKey(char ch){
        return links[ch-'a'] != NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};


class Trie{

private : 
    Node* root ;


public :

    Trie(){
        root = new Node();
    }

    void insert(string word){   // TC = O(n) , n = length of word
        Node* node = root ;
        for(int i=0;i<word.size(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){   // TC = O(n) , n = length of word
        Node* node = root ;
        for(int i=0;i<word.size(); i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix){   // TC = O(n) , n = length of word
        Node* node = root ;
        for(int i=0;i<prefix.size(); i++){
            if(!node->containKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }



};

