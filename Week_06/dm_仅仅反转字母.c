char * reversestr(char * s, int start, int end){
    char tmp;
    while(start < end){
        tmp = s[end];
        s[end--] = s[start];
        s[start++] = tmp;
    }
    return s;
}

char * reverseOnlyLetters(char * S){
    char* tmp = (char*)malloc(sizeof(char)*100);
    int k = 0;
    int l = 0;
    int len_S = strlen(S);
    char* ret = (char*)malloc(sizeof(char)*101);
    for(int i = 0; i < len_S; i++){
        if((S[i] >= 'a'&& S[i] <= 'z')||(S[i] >= 'A' && S[i] <= 'Z')){
            tmp[k++] = S[i];
        }
    }
    tmp = reversestr(tmp,0,k-1);
    k = 0;
    for(int i = 0; i < len_S; i++){
        if((S[i] >= 'a'&& S[i] <= 'z')||(S[i] >= 'A' && S[i] <= 'Z')){
            ret[k++] = tmp[l++]; 
        }
        else{
            ret[k++] = S[i];
        }
    }
    ret[k] = '\0';
    return ret;
}