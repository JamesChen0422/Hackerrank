
int beautifulBinaryString(char* b) {
    int i=0,count=0;
    while(b[i]){
        if(b[i]=='0'&& b[i+1]=='1' && b[i+2]=='0'){
            b[i+2]='1';
            count++;
        }
        i++;
    }
    return count;
}