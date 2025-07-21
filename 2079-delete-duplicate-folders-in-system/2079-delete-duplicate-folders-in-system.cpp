class Solution {
public:
    struct TrieNode {
        unordered_map<string, TrieNode*> children;
        string name;
        bool toDelete = false;
    };

    unordered_map<string, int> freq; 

    void insert(TrieNode* root, const vector<string>& path) {
        TrieNode* node = root;
        for (const string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new TrieNode();
                node->children[folder]->name = folder;
            }
            node = node->children[folder];
        }
    }

    string serialize(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<string> subs;
        for (auto& [name, child] : node->children) {
            subs.push_back(name + "(" + serialize(child) + ")");
        }

        sort(subs.begin(), subs.end());  // Ensure serialization
        string serial = accumulate(subs.begin(), subs.end(), string());
        freq[serial]++;
        return serial;
    }

    string mark(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<string> subs;
        for (auto& [name, child] : node->children) {
            subs.push_back(name + "(" + mark(child) + ")");
        }

        sort(subs.begin(), subs.end());
        string serial = accumulate(subs.begin(), subs.end(), string());

        if (freq[serial] > 1) {
            node->toDelete = true;
        }

        return serial;
    }

    void collect(TrieNode* node, vector<string>& currentPath, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (child->toDelete) continue;

            currentPath.push_back(name);
            result.push_back(currentPath);
            collect(child, currentPath, result);
            currentPath.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();

        for (const auto& path : paths) {
            insert(root, path);
        }

        for (auto& [name, child] : root->children) {
            serialize(child);
        }

        for (auto& [name, child] : root->children) {
            mark(child);
        }

        vector<vector<string>> result;
        vector<string> currentPath;
        collect(root, currentPath, result);

        return result;
    }
};