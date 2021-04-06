#include <iostream>
#include <cmath>

std::string encrypt_caesar(std::string encryptText, int number)
{
    for (int i=0; i < encryptText.length(); i++){
        bool bigLetter = encryptText[i] >= 'A' && encryptText[i] <= 'Z';
        bool corLetter = (encryptText[i] >= 'a' && encryptText[i] <= 'z') || (encryptText[i] >= 'A' && encryptText[i] <= 'Z');
        int int_letter=0;
        !bigLetter ? int_letter = encryptText[i] - ('a'-1) : int_letter = encryptText[i] - ('A'-1);
        for (int count = std::abs(number); count > 0 && corLetter; count--){
            number > 0 ? (int_letter >= 26 ? int_letter = 1 : int_letter++) : (int_letter <= 1 ? int_letter = 26 : int_letter--);
        }
        !bigLetter ? encryptText[i] = ('a'-1) + int_letter : encryptText[i] = ('A'-1) + int_letter;
    }
    return encryptText;
}
std::string decrypt_caesar(std::string decryptText, int number){
   return encrypt_caesar(decryptText,number * -1);
}

int main() {
    std::string text;
    int shift;
    bool cor = true;
    std::cout << "Enter text : ";
    std::getline(std::cin,text);
    std::cout << "Enter shift : ";
    std::cin >> shift;
    text = encrypt_caesar(text,shift);
    std::string test;
    std::cout << "Ciphertext :" << text << std::endl;
    std::cout << "Decrypted text :" << decrypt_caesar(text, shift);
}
