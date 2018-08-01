#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

//chat box: oh yeah xD
using namespace std;

string encrypt(const string &message, vector<char> currentLang){

  string tmp;
	auto last = currentLang.end() - 1;
	auto secondLast = currentLang.end() - 2;

	int matches;

   for(auto elem : message){
		 matches = 0;
     for(auto iter = currentLang.begin(); iter != currentLang.end(); ++iter){
       if (elem == *iter){
					++matches;
         if (elem == *last){
           tmp += *(currentLang.begin() + 1);
         } else if(elem == *secondLast){
           	tmp += *(currentLang.begin());
         } else if(elem == *iter){
           	tmp += *(iter + 2);
      	}

			}
 		}
		if(matches == 0){
			tmp += elem;
		}
	}
   reverse(tmp.begin(), tmp.end());
   return tmp;
}

string decrypt(string &message, vector<char> currentLang){

  string tmp, reversedMessage;

  reverse(message.begin(), message.end());
  reversedMessage =  message;

	auto first = currentLang.begin();
	auto second = currentLang.begin() + 1;

	int matches;

  for(auto elem : reversedMessage){
    matches = 0;
    for(auto iter = currentLang.begin(); iter != currentLang.end(); ++iter){
      if (elem == *iter){
        ++matches;
        if (elem == *first){
          tmp += *(currentLang.end() - 2);
        } else if(elem == *second){
          tmp += *(currentLang.end() - 1);
        } else if(elem == *iter){
          tmp += *(iter - 2);
      	}

			}
 		}
		if(matches == 0){
			tmp += elem;
		}
	}
  return tmp;
}

//function my ass
int main(){
  vector<char> english {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char input;

  string message, NewMessage;

  cout << "Would you like to:\na)Encrypt\nb)Decrypt" << endl;
  cout << ">> ";
  cin >> input;
	cout << endl;

  if (input == 'a'){
    cout << "Enter message to be encrypted: " << endl;
		cin.ignore();
    getline(cin, message);
    NewMessage = encrypt(message, english);
    cout << NewMessage << endl;

  }else if(input == 'b'){
    cout << "Enter message to be decrypted" << endl;
    cin.ignore();
    getline(cin, message);
    NewMessage = decrypt(message, english);
    cout << NewMessage << endl;

  }

  return 0;
}
