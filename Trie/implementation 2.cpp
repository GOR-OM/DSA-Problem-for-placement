#include<bits/stdc++.h>
using namespace std;

// | INSERT | countWordsEqualTo() | countWordsStartingWith()



struct  Node{
    Node* links[26];
    int EndWith =0;
    int PrefixWith = 0; 

    bool containKey(char ch){
        return links[ch-'a'] != NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void increaseEndWith(){
        EndWith++;
    }

    void increasePrefixWith(){
        PrefixWith++;
    }
    void decreaseEndWith(){
        EndWith--;
    }

    void reducePrefixWith(){
        PrefixWith--;
    }


};


class Trie{

private : 
    Node* root ;

public : 
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root ;
        for(int i=0;i<word.size(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefixWith();
        }
        node->increaseEndWith();
    }


    int CountWordsEqualTo(string &word){
        Node* node = root ;
        for(int i=0;i<word.size(); i++){
            if(!node->containKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->EndWith;
    }

    int countWordsStartingWith(string &prefix){
        Node* node = root ;
        for(int i=0;i<prefix.size(); i++){
            if(!node->containKey(prefix[i])){
                return 0;
            }
            node = node->get(prefix[i]);
        }
        return node->PrefixWith;
    }

    void erase(string &word){
        Node* node = root ;
        for(int i=0;i<word.size(); i++){
            if(!node->containKey(word[i])){
                return ;
            }
            node = node->get(word[i]);
            node->reducePrefixWith();
        }
        node->decreaseEndWith();
    }


    
};

