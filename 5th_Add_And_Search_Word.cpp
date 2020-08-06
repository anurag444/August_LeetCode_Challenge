/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

*/

//SOLUTION - I will be using Trie data structure to solve this problem


class WordDictionary {
    vector<WordDictionary*> child;
    bool isEnd;
public:
    /** Initialize your data structure here. */
    WordDictionary(): isEnd(false) {
        child = vector<WordDictionary*>(26, nullptr);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *curr = this;
        for(char c: word){
            if(curr->child[c-'a'] == nullptr)
                curr->child[c- 'a'] = new WordDictionary();
            curr = curr->child[c-'a'];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary *curr = this;
        for(int i = 0 ; i<word.length(); i++){
            char c= word[i];
            if(c == '.'){
                for(auto ch: curr->child)
                    if(ch && ch->search(word.substr(i+1))) return true;
                return false;
            }
            
            if(curr-> child[c-'a'] == nullptr) return false;
            curr = curr->child[c-'a'];
        }
        return curr && curr->isEnd;
    }
};
