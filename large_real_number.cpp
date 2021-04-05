#include <iostream>
using namespace std;
string number;
string number1;
string number2;
int positionPoint1 = 0;
int positionPoint2 = 0;
bool negativeNumber;
bool correct_Number(int number_number){
    if (number_number < 0 || number_number > 2){
        cout << "\nfunction call error! invalid parameter !\n";
        return false;
    }
    if (number_number == 1){
        number = number1;
    }else if (number_number == 2){
        number = number2;
    }
    bool onlyNumber=false;
    bool correctSign=false;
    int counterPoint=0;
    for (int i=0; i < number.length(); i++){
        if (number[i] >= '0' && number[i] <= '9'){
            onlyNumber = true;
        }else if ((number[i] < '0' || number[i] > '9') && (number[i] != '.' && number[i] != '-')){
            return false;
        }
        if (number[i] == '.'){
            counterPoint++;
            number_number == 1 ? positionPoint1 = i : positionPoint2 = i;
        }
        counterPoint <= 1 ? correctSign = true : correctSign = false;
        if ((number[0] == '-' || number[0] == '.') && i == 0){
            correctSign = true;
        }else if (number[i] == '-' && i != 0){
            return false;
        }
    }
    if (onlyNumber && correctSign){
        return true;
    }
    return false;
}
string get_part(int num,bool intOrFract){
    string outputPart;
    int positionPoint;
    if (num == 1){
        number = number1;
        positionPoint = (positionPoint1 == 0 && number[0] != '.') ? (int)number.length() : (int)positionPoint1;
    }else if (num == 2){
        number = number2;
        positionPoint =  (positionPoint2 == 0 && number[0] != '.') ? (int)number.length() : (int)positionPoint2;
    }else {
        cout << "\ninvalid parameter passed\n";
        return "error";
    }
    for (int i = (intOrFract ? 0:(positionPoint + 1)); i < (intOrFract ? positionPoint : number.length()); i++){
        outputPart += number[i];
    }
    return outputPart;
}
string correct_Part (string numb, bool intOrFract){
    string correctPart;
    int length1 = (int)get_part(1, intOrFract).length();
    int length2 = (int)get_part(2, intOrFract).length();
    int shift = abs(length1 - length2);
    if (numb[0] == '-'){
        correctPart += '-';
        numb.erase(0,1);
    }
    for (int i = 0; i < shift; i++){
        intOrFract ? correctPart += '0' : numb += '0';
    }
    return intOrFract ? correctPart += numb : numb;
}
int main() {
    string intPart1;
    string intPart2;
    string fractPart1;
    string fractPart2;
    cout << "enter 'exit' to exit\n";
    while (true){
        cout << "Enter number 1,2 : \n";
        cin >> number1;
        if (number1 == "exit"){
            return 0;
        }
        cin >> number2;
        bool sameLengthInt;
        bool sameLengthFract;
        if (correct_Number(1) && correct_Number(2)) {

            intPart1 = get_part(1,true);
            intPart2 = get_part(2,true);
            fractPart1 = get_part(1,false);
            fractPart2 = get_part(2,false);
            sameLengthInt = intPart1.length() == intPart2.length();
            sameLengthFract = fractPart1.length() == fractPart2.length();
            negativeNumber = number1[0] == '-' && number2[0] == '-';
             if (!sameLengthInt){
               string correctPart = correct_Part(((int)intPart1.length() < (int)intPart2.length()) ? intPart1 : intPart2, true);
               if (intPart1.length() < intPart2.length()){
                   intPart1 = correctPart;
               }else if (intPart2.length() < intPart1.length()){
                   intPart2 = correctPart;
               }
             }
             if (!sameLengthFract){
                 string correctPart = correct_Part((int)fractPart1.length() < (int)fractPart2.length() ? fractPart1 : fractPart2, false);
                 if (fractPart1.length() < fractPart2.length()){
                     fractPart1 = correctPart;
                 }else if (fractPart2.length() < fractPart1.length()){
                     fractPart2 = correctPart;
                 }
             }
            if (intPart1 > intPart2) {
                !negativeNumber ? cout << "More\n" : cout << "Less\n";
            } else if (intPart1 == intPart2) {
                if (fractPart1 > fractPart2){
                    !negativeNumber ? cout << "More\n" : cout << "Less\n";
                }else if (fractPart1 == fractPart2){
                    cout << "Equal\n";
                }else !negativeNumber ? cout << "Less\n" : cout << "More\n";
            } else !negativeNumber ? cout << "Less\n" : cout << "More\n";
            positionPoint1 = 0;
            positionPoint2 = 0;
        }else cout << "number not correct\n";
    }
}