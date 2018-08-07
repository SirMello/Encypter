# Ligma Machine

An Engima like encrypter made by me and a friend of mine named [Happy Seaweed](https://github.com/Happyseaweed). At the moment, we don't have many features. The only feature that is worth noting is the ability to input a key to scramble your message. This key is 5 digits has a scrambling algorithm added for extra security. :)

## Getting Started

To get started clone the project to your system via the clone button or ```git clone https://github.com/SirMello/Encypter.git```
Prerequisites

You will need a C++ compiler that is C++11 or later.

To install on Linux:

```
sudo apt get g++ 
```

On Mac, you need to get the Command Line Tools. (Install Xcode)

## Installing

Start by going to your terminal for your computer

1. Git clone this project to your system
```
git clone https://github.com/SirMello/Encypter.git
```

2. Go to the source files directory
```
cd Encrypter/src
```

3. Create the execuable file
```
g++ main.cpp keyGenerator.cpp arrayWrapping.cpp -o sample
```

4. Run the execuable file
```
./sample
```

You should see some output similar to this:
```
Please choose an option: 
A) Encrypt 
B) Decrypt 
```

## Built With

* [g++](https://gcc.gnu.org) - C++ compiler used(may vary on other systems)

## Authors

* **Me** - Developed the beta/eariler verison and worked on this verison - [SirMello](https://github.com/SirMello)
* **Seaweed** - Worded on this verison and created the algorithm for our Engima - [HappySeaweed](https://github.com/Happyseaweed)

## License

**WORK IN PROGESS**

## Acknowledgments

Credit to Arthur Scherbius for creating the **real** Engima machine
