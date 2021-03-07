void reversestr(char*s, int start, int end)
{
    int temp;
    while(start<end)
    {
        temp=s[end];
        s[end--]=s[start];
        s[start++]=temp;
    }
}

char * reverseStr(char * s, int k){
    int len_s = strlen(s);
    int i = 0;
    while(i < len_s){
        int j = fmin(i + k - 1,len_s - 1);
        reversestr(s,i,j);
        i += 2 * k;
    }
    return s;
}

