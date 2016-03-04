struct TrieNode {
    bool exist;
    struct TrieNode* next[26];
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    int i;
    struct TrieNode* root=(struct TrieNode*)malloc(sizeof(struct TrieNode));
    root->exist=false;
    for(i=0;i<26;i++){
        root->next[i]=NULL;
    }
    
    return root;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    int i,j;
    struct TrieNode *p;
    p=root;
    for(i=0;i<strlen(word);i++){
        if(p->next[word[i]-'a']==NULL){
            p->next[word[i]-'a']=(struct TrieNode*)malloc(sizeof(struct TrieNode));
            for(j=0;j<26;j++){
                p->next[word[i]-'a']->next[j]=NULL;
            }
            p->next[word[i]-'a']->exist=false;
        }
        if(i==strlen(word)-1){
            p->next[word[i]-'a']->exist=true;
        }
        p=p->next[word[i]-'a'];
    }
    
    return;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    int i;
    struct TrieNode *p;
    p=root;
    for(i=0;i<strlen(word);i++){
        if(p->next[word[i]-'a']==NULL){
            return false;
        }
        if(i==strlen(word)-1&&p->next[word[i]-'a']->exist==false){
            return false;
        }
        p=p->next[word[i]-'a'];
    }
    
    return true;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    int i;
    struct TrieNode *p;
    p=root;
    for(i=0;i<strlen(prefix);i++){
        if(p->next[prefix[i]-'a']==NULL){
            return false;
        }
        p=p->next[prefix[i]-'a'];
    }
    return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    int i;
    for(i=0;i<26;i++){
        if(root->next[i]!=NULL){
            trieFree(root->next[i]);
        }
    }
    free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);
