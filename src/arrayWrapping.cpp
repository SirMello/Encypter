#include "../include/arrayWrapping.h"
int encryptWrap(int x){
    return x - 51;
}

int decryptWrap(int x){
    return x + 51;
}
