int firstUniqChar(char * s){
    int len_s = strlen(s);
    int hash_table[26] = { 0 };
    for(int i = 0; i < len_s; i++){
        hash_table[s[i] - 'a'] ++;
    }
    for(int i = 0; i < len_s; i++){
        if(hash_table[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}