class Trie {
public:
    struct TrieNode {
        bool isWord;
        TrieNode* children[26];
        // unordered_map<char, TrieNode*> children;

        TrieNode() {
            isWord = false;
            for(auto child : children) {
                child = NULL;
            }
        }
    };

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;

        for(int i = 0; i < word.length(); i++) {
            if(cur->children[word[i]-'a'] == NULL)
                cur->children[word[i]-'a'] = new TrieNode();
            
            cur = cur->children[word[i]-'a'];
        }

        cur->isWord = true;
    }

    bool search(string word) {
        if(word.length() == 0) return false;

        TrieNode* cur = root;

        for(int i = 0; i < word.length(); i++) {
            if(cur->children[word[i]-'a'] == NULL)
                return false;
            
            cur = cur->children[word[i]-'a'];
        }

        return cur->isWord;
    }

    bool startWith(string prefix) {
        if(prefix.length() == 0) return false;

        TrieNode* cur = root;

        for(int i = 0; i < prefix.length(); i++) {
            if(cur->children[prefix[i]-'a'] == NULL)
                return false;

            cur = cur->children[prefix[i]-'a'];
        }

        return true; // diff with word search.
    }
}