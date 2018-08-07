#include "../include/arrayWrapping.h"
int encryptWrap(int x, int sze){
    return x % sze;
}

int decryptWrap(int x, int sze){
  if(x >= 0){
    return x;
  }else {
    return x + sze;
  }

}
