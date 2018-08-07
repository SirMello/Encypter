#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "../include/arrayWrapping.h"
#include "../include/keyGenerator.h"

// the algorithem function:
//the setting(key) 5 numbers with scramble:

#ifndef NDEBUG
void debug(){
    static int times;
    std::cout << "Debug test.\n"
              <<  "Amount of times \'debug\' was called: " << ++times << std::endl;
}
#endif


//--------------------------------------MAIN------------------------------------
int main(){
  int engSize = 84;
  char option;
  std::string message, newMessage, input;
  int arrCnt = 0, matches = 0, letter = 0;
  unsigned keys[5] = {0};
  unsigned keyList[5] = {0};

//----------------------------------ARRAY---------------------------------------
  char eng[84] = {
                  // Lowercase letters
                  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

                  //Uppercase letters
                  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',

                  //Puncuation characters
                  '`', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_',
                  '=', '+', '[', ']', '{', '}', '\\', '|', ';', ':', '\'', '\"',
                  ',', '<', '.', '>', '/', '?', ' '};




//----------------------------------OPTION SELECTION----------------------------
  std::cout << "Please choose an option: " << std::endl;
  std::cout << "A) Encrypt " << '\n';
  std::cout << "B) Decrypt " << '\n' << std::endl;
  std::cin >> option;

//----------------------------------ENCRYPTION----------------------------------
  if (toupper(option) == 'A'){
    keyGen(keys, 5);

  //----------------------------------SCRAMBLED PROCCESS------------------------
  std::cout << "[Your new scrambled unique key is:";
  for (int i = 0; i < 5; ++i){
    std::cout << " " << keys[i];
  }
  std::cout << "]" << std::endl;

  std::cout << std::endl;
  std::cout << "**REMEMBER** If you want to DECRYPT your message, input your PREVIOUS key, not the SCRAMBLED one." << std::endl;
  std::cout << std::endl;

  std::cout << "Please enter your message for encryption." << std::endl;
  std::cout << ">> ";
  std::cin.ignore();
  std::getline(std::cin, message);
  for (auto elem : message){
    matches = 0;
    for (int c = 0; c < engSize; ++c){
      if (elem == eng[c]){
        letter = c + keys[arrCnt];
        if (letter <= engSize - 1){
            ++matches;
            if(arrCnt == 4){
                newMessage += eng[letter];
                arrCnt = 0;
            }else{
                newMessage += eng[letter];
                ++arrCnt;
            }

        }else{
            letter = encryptWrap(letter, engSize);
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
  std::cout << "ENCRYPTED: " << newMessage << std::endl;

//----------------------------------DECRYPTION----------------------------------
  } else if(toupper(option) == 'B'){
    std::cout << "Please enter your 5-digit key: " << std::endl;
    std::cin >> input;

    if (input.size() == 5){
      for(int i = 0; i != input.size(); ++i){
        int stringValue = input[i] - '0';
        keyList[i] = stringValue;
      }
    }
    keyGen(keys, 5, keyList);

    std::cout << std::endl;
    std::cout << "[This SCRAMBLED key will be used to DECRYPT your message:";
    for (int i = 0; i < 5; ++i){
      std::cout << " " << keys[i];
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;

//----------------------------------DECRYPTION----------------------------------
    std::cout << "Please enter your message for decryption. " << std::endl;
    std::cout << ">> ";
    std::cin.ignore();
    std::getline(std::cin, message);

    for (auto elem : message){
      matches = 0;
      for (int c = 0; c < engSize; ++c){
        if (elem == eng[c]){
          letter = c - keys[arrCnt];
          if (letter >= 0){
            ++matches;
            if(arrCnt == 4){
                newMessage += eng[letter];
                arrCnt = 0;
            }else{
                newMessage += eng[letter];
                ++arrCnt;
            }

          } else{
            letter = decryptWrap(letter, engSize);
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
    std::cout << "DECRYPTED: " << newMessage << std::endl;
  }
}
