#include <string>
#include <iostream>

using namespace std;

void getNext(string pattern, int next[]){
    int len = pattern.size();
    int j = 0;
    next[0] = 0;
    for(int i = 1; i < len; i++){
        while(j >0 && pattern[i] != pattern[j]){
            j = next[j-1];
        }
        if(pattern[i] == pattern[j]){
            ++j;
        }
        next[i] = j;
    }
}

void getNextval(string pattern, int next[], int nextval[]){
   int len = pattern.size();
    for(int i = 0; i < len; i++){
        if(pattern[i] == pattern[next[i]]){
            nextval[i] = next[next[i]];
        }else{
            nextval[i] = next[i];
        }
    }
}

void getFinal(int next[], int len){
    for(int i = len-1; i > 0; i--){
        next[i] = next[i-1];
    }
    next[0] = -1;
}

void kmp(string pattern, string text) {
    int len = pattern.size();
    int l = text.size();
    
    int next[len];
    int nextval[len];
    
    getNext(pattern, next);
    getNextval(pattern, next, nextval);
    getFinal(nextval, len);
    
    int i = 0, j = 0;
    while(i < l && j < len){
        if(pattern[j] == text[i]){
            i++;j++;
        }else{
            j = nextval[j];
            if(j == -1){
                i++;j++;
            }
        }
        if(j == len){
            cout<<"find substring in position "<<i-len<<" : "<<text.substr(i-len,len)<<endl;
            j = nextval[len-1];
        }
    }
}
