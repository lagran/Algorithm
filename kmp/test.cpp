#include "kmp.h"
#include <iostream>

using namespace std;

int main(){
    string pattern, text;
    cout<<"please input patten: ";
    cin>>pattern;
    cout<<"please input text: ";
    cin>>text;
    kmp(pattern, text);
    return 0;
}
