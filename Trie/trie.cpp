struct trie{
    int cnt;
    bool isend;
    struct trie * node[2];
};

struct trie* getnode(){
    struct trie * ptr = new struct trie;
    ptr -> cnt = 0;
    ptr -> isend = 0;
    ptr -> node[0] = ptr -> node[1] = NULL;
    return ptr;
}

struct trie * head = getnode();

void insert(int x){
    struct trie * temp = head;
    for(int i = 29; i >= 0; i--){
        int bit = (x >> i) & 1;
        if(temp -> node[bit] != NULL){
	    temp = temp -> node[bit];
            temp -> cnt++;
            continue;
        }
        temp -> node[bit] = getnode();
        temp = temp -> node[bit];
        temp -> cnt++;
    }
    temp -> isend = 1;
}

bool ispresent(int x){
    struct trie * temp = head;
    for(int i = 29; i >= 0; i--){
        int bit = (x >> i) & 1;
        if(!(temp -> node[bit]))
            return 0;
        temp = temp -> node[bit];
        if(temp -> cnt <= 0)
            return 0;
    }
    return (temp && temp -> isend && temp -> cnt > 0);
}

void erase(int x){
    struct trie * temp = head;
    for(int i = 29; i >= 0; i--){
        int bit = (x >> i) & 1;
        temp = temp -> node[bit];
        (temp -> cnt)--;
    }
    temp -> isend = 0;
}
