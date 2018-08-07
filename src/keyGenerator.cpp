#include "../include/keyGenerator.h"

void keyGen(unsigned (&arr)[5], size_t sze){
  std::cout << " Input five numbers between 0 - 9 seperated by spaces and press [ENTER] when you are done." << std::endl;

  for(int i = 0; i != sze; ++i){
    std::cin >> arr[i];
  }

  unsigned tmp = arr[0];

  for(int i = 0; i != sze; ++i){
    if (arr[i] == arr[4]){
      arr[i] = arr[i] + tmp;
    } else {
      arr[i] = arr[i] + arr[i + 1];
    }
  }
  return;
}


void keyGen(unsigned (&arr)[5], size_t sze, unsigned const (&keys)[5]){
  unsigned tmp = keys[0];

  for(int i = 0; i != sze; ++i){
    if (keys[i] == keys[4]){
      arr[i] = keys[i] + tmp;
    } else {
      arr[i] = keys[i] + keys[i + 1];
    }
  }
  return;
}
