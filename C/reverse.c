char* reverse(char* word){
    
    int count = 0;

    for(int n = 0; word[n] != '\0'; ++n){
        ++count;
    }
    
    int half = count / 2;
    int last = count - 1;

    
    for(int n = 0; n < half; ++n){
        char temp = word[n];
        word[n] = word[last - n];
        word[last - n] = temp;
    }
    
    return word;
    
}