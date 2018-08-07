#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "../include/arrayWrapping.h"
#include "../include/keyGenerator.h"

// the algorithem function:
//the setting(key) 5 numbers with scramble:

void debug(){
    static int times;
    std::cout << "Debug test.\n"
              <<  "Amount of times \'debug\' was called: " << ++times << std::endl;
}


//--------------------------------------MAIN------------------------------------
int main(){
  char option;
  std::string message, newMessage;
  int arrCnt = 0, matches = 0, letter = 0;
  unsigned keys[5] = {0};
  unsigned keyList[5] = {0};

//----------------------------------ARRAY----------------------------------
  char eng[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

                  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


//----------------------------------OPTION SELECTION----------------------------------
  std::cout << "Please choose an option: " << std::endl;
  std::cout << "A) Encrypt " << '\n';
  std::cout << "B) Decrypt " << '\n' << std::endl;
  std::cin >> option;

//----------------------------------ENCRYPTION------------------------------------
  if (toupper(option) == 'A'){
    keyGen(keys, 5);

  //----------------------------------SCRAMBLED PROCCESS----------------------------------
    std::cout << " [◊◊Scrambled◊◊] " << std::endl;
    for (int i = 0; i < 5; ++i){
      std::cout << keys[i] << std::endl;
    }

  std::cout << "Please Enter your Message for Encryption: " << std::endl;
  std::cin.ignore();
  std::getline(std::cin, message);
  for (auto elem : message){
    matches = 0;
    for (int c = 0; c < 52; ++c){
      if (elem == eng[c]){
        letter = c + keys[arrCnt];
        if (letter <= 51){
            ++matches;
            if(arrCnt == 4){
                newMessage += eng[letter];
                arrCnt = 0;
            }else{
                newMessage += eng[letter];
                ++arrCnt;
            }

        }else{
            letter = encryptWrap(letter);
            ++matches;
            if(arrCnt == 4){
                newMessage += eng[letter];
                arrCnt = 0;
            }else{
                newMessage += eng[letter];
                ++arrCnt;
            }
        }


      }
    }
    if (matches == 0){
      if(arrCnt == 4){
        newMessage += elem;
        arrCnt = 0;
      }else{
        newMessage += elem;
        ++arrCnt;
      }
    }
  }
  std::cout << newMessage << std::endl;

//----------------------------------DECRYPTION----------------------------------
}else if(toupper(option) == 'B'){
  std::cout << "Please enter your 5-digit key: " << std::endl;
  for (size_t s = 0; s < 5; s++) {
    std::cin >> keyList[s];
  }
  keyGen(keys, 5, keyList);

  std::cout << " [◊◊Scrambled◊◊] " << std::endl;
  for (int i = 0; i < 5; ++i){
    std::cout << keys[i] << std::endl;
  }
//----------------------------------DECRYPTION----------------------------------
  std::cout << "Please Enter your Message for Encryption: " << std::endl;
  std::cin.ignore();
  std::getline(std::cin, message);
  for (auto elem : message){
    matches = 0;
    for (int c = 0; c < 52; ++c){
      if (elem == eng[c]){
        letter = c - keys[arrCnt];
        if (letter >= 0){
            goto decrypt;
        }else if (letter - 1 >= 0){
decrypt:
            ++matches;
            if(arrCnt == 4){
                newMessage += eng[letter];
                arrCnt = 0;
            }else{
                newMessage += eng[letter];
                ++arrCnt;
            }

        }else{
            letter = decryptWrap(letter);
            ++matches;
            if(arrCnt == 4){
                newMessage += eng[letter];
                arrCnt = 0;
            }else{
                newMessage += eng[letter];
                ++arrCnt;
            }
        }


      }
    }
    if (matches == 0){
      if(arrCnt == 4){
        newMessage += elem;
        arrCnt = 0;
      }else{
        newMessage += elem;
        ++arrCnt;
      }
    }
  }
  std::cout << newMessage << std::endl;
}
}
