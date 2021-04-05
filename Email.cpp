#include <iostream>
std::string email;
std::string allowedChar = "!#$%&'*+-/=?^_`{|}~";
std::string half (std::string half){
    bool checkDog = false;
    std::string emailHalf;
    for (int count=0; count < email.length(); count++){
        bool sy = email[count] != '@';
        if (!sy) {
            if (checkDog) {
                std::cout << "\nError ! '@' more then 2\n";
                return "error";
            }
            checkDog = true;
        }
        if (sy && !checkDog && half == "first"){
            emailHalf += email[count];
        }else if (sy && checkDog && half == "second"){
            emailHalf += email[count];
        }
    }
    if (checkDog){
        return emailHalf;
    }else {
        std::cout << "\nError ! missing sign '@'\n";
        return "error";
    }
}
bool checkHalf (std::string part){
    std::string emailHalf;
    if (part == "first"){
        emailHalf = half("first");
    }else if (part == "second"){
        emailHalf = half("second");
    }
    if (emailHalf.length() > (part == "first" ? 64:63) || emailHalf.length() < 1){
        std::cout << "\nLong line error !\n";
        return false;
    }
    int pointCounter = 0;
    for (int i=0; i < emailHalf.length(); i++){
        char sy = emailHalf[i];
        bool specialChar = false;

        for (int count=0; count < allowedChar.length() && part == "first"; count++){
            char allChar = allowedChar[count];
            if (sy == allChar) specialChar = true;
        }
        if (((sy < 'a' || sy > 'z') && (sy < 'A' || sy > 'Z')) &&
                (sy < '0' || sy > '9') && sy != '-' && !specialChar && sy != '.' ||
                (emailHalf[0] == '.' || emailHalf[emailHalf.length() - 1] == '.')) {
            std::cout << "\nError ! not correct character\n";
            return false;
        }else if ((i >= 1 && sy == '.') && emailHalf[i-1] == '.'){
            std::cout << "\nError ! dots more then 2\n";
            return false;
        }
    }
    return true;
}
int main() {
    std::string firstHalf;
    std::string secondHalf;
    std::cout << "Enter email :";
    std::getline(std::cin, email);
    if (half("first") == "error"){
        std::cout << "Email not correct !";
    }else if (checkHalf("first") && checkHalf("second")){
        std::cout << "Email address corrected\n";
    }else std::cout << "Email address not corrected\n";
    return 0;
}