## 208. Implement Trie (Prefix Tree)[Medium]

Implement a trie with insert, search, and startsWith methods.

**Example:**
```java
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
```

***Note:***
- You may assume that all inputs are consist of lowercase letters a-z.
- All inputs are guaranteed to be non-empty strings.

## [Solution Analysis](https://leetcode.com/problems/implement-trie-prefix-tree/solution/)

```c++
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : terminal(false), dict(26, nullptr){
               
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * cur = this;
        
        char c = 0;
        for (int i = 0; i < word.size(); i++)
        {
            c = word[i];
            
            if (nullptr == cur->dict[c-'a'])
            {
                cur->dict[c-'a'] = new Trie();
            }
            
            cur = cur->dict[c-'a'];            
        }
        cur->terminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * cur = this;
        
        char c = 0;
        for (int i = 0; i < word.size(); i++)
        {
            c = word[i];
            if (nullptr == cur->dict[c-'a']) return false;
            
            cur = cur->dict[c-'a'];
        }
        
        return cur->terminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie * cur = this;
        
        char c = 0;
        for (int i = 0; i < prefix.size(); i++)
        {
            c = prefix[i];
            if (nullptr == cur->dict[c-'a']) return false;
            
            cur = cur->dict[c-'a'];            
        }
        
        return true;
    }
    
private:
    bool terminal;
    vector<Trie*> dict;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```