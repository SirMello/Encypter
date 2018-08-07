#include "../include/keyGenerator.h"

void keyGen(unsigned (&arr)[5], int sze){
  std::string input;

  std::cout << " Input five numbers between 0 - 9 and press [ENTER] when you are done." << std::endl;
  std::cin >> input;

  if (input.size() == 5){
    for(int i = 0; i != input.size(); ++i){
      int stringValue = input[i] - '0';
      arr[i] = stringValue;
    }

  }

  std::cout << "[Your unique key is used for DECRYPTION:";
  for (int i = 0; i < 5; ++i){
    std::cout << " " << arr[i];
  }
  std::cout << "]" << std::endl;

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


void keyGen(unsigned (&arr)[5], int sze, unsigned const (&keys)[5]){
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
