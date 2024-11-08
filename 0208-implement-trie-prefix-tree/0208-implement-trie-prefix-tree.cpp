class Trie
{
    public:
        struct TrieNode
        {
            bool endword;
            TrieNode *children[26];
        };
    TrieNode* getNode()
    {
        TrieNode *newnode = new TrieNode();
        newnode->endword = false;
        for (int i = 0; i < 26; i++)
        {
            newnode->children[i] =nullptr;
        }
        return newnode;
    }
    TrieNode * root;
    Trie()
    {
        root = getNode();
    }

    void insert(string word)
    {
        TrieNode *ptr = root;
        
        for (int i = 0; i < word.size(); i++)
        {   int idx= word[i]-'a';
            if (ptr->children[idx] == nullptr)
            {
                ptr->children[idx] = getNode();
            }
            ptr = ptr->children[idx];
        }
        ptr->endword = true;
    }

    bool search(string word)
    {
        TrieNode *ptr = root;
        for (int i = 0; i < word.size(); i++)
        {   int idx= word[i]-'a';
            if (ptr->children[idx] == nullptr)
            {
                return false;
            }
            ptr = ptr->children[idx];
        }
        return  ptr->endword ;
    }

    bool startsWith(string prefix)
    {
        TrieNode *ptr = root;
        int i = 0;
        for (; i < prefix.size(); i++)
        {   int idx= prefix[i]-'a';
            if (ptr->children[idx] == nullptr)
            {
                return false;
            }
            ptr = ptr->children[idx];
        }
        return i == prefix.size();
    }
};

/**
 *Your Trie object will be instantiated and called as such:
 *Trie* obj = new Trie();
 *obj->insert(word);
 *bool param_2 = obj->search(word);
 *bool param_3 = obj->startsWith(prefix);
 */