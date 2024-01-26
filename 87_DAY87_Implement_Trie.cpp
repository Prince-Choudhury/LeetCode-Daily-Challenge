class TrieNode {
public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val) {
        this->value = val;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie {
private:
    TrieNode* root;

    void insertWord(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            // present
            child = root->children[index];
        } else {
            // absent
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        // recursion
        insertWord(child, word.substr(1));
    }

    bool searchWord(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            // present or found
            child = root->children[index];
        } else {
            // not found
            return false;
        }

        // recursion
        bool recursionKaAns = searchWord(child, word.substr(1));
        return recursionKaAns;
    }

    bool startsWithPrefix(TrieNode* root, string prefix) {
        // base case
        if (prefix.length() == 0) {
            return true;
        }

        char ch = prefix[0];
        int index = ch - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            // child present
            child = root->children[index];
        } else {
            return false;
        }

        // recursive call
        bool recursionKaAns = startsWithPrefix(child, prefix.substr(1));
        return recursionKaAns;
    }

public:
    Trie() {
        root = new TrieNode('\0'); // root node with null character
    }

    void insert(string word) {
        insertWord(root, word);
    }

    bool search(string word) {
        return searchWord(root, word);
    }

    bool startsWith(string prefix) {
        return startsWithPrefix(root, prefix);
    }
};

