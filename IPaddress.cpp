#include <iostream>
std::string ipAddress;
int point_1;
int point_2;
int point_3;
bool check_all_string (){
    if (ipAddress.length() > 15){
        std::cout << "\nError length string\n";
        return false;
    }
    int pointCounter = 0;
    for (int numSy=0; numSy < ipAddress.length(); numSy++){
        char symbol = ipAddress[numSy];
        if (ipAddress[0] == '.' || ipAddress[ipAddress.length() - 1] == '.'){
            std::cout << "\nfirs or last character '.'\n";
            return false;
        }else if (numSy >= 1 && symbol == '.' && ipAddress[numSy - 1] == '.'){
            std::cout << "\ntwo points in a row\n";
            return false;
        }else if (symbol == '.'){
            pointCounter++;
            if (pointCounter == 1){
                point_1 = numSy;
            }else if (pointCounter == 2){
                point_2 = numSy;
            }else if (pointCounter == 3){
                point_3 = numSy;
            }
        }
        if (symbol != '.' && symbol < '0' || symbol > '9'){
            std::cout << "\ninvalid characters are present\n";
            return false;
        }
    }
    if (pointCounter != 3){
        std::cout << "\ndots more or less than three\n";
        return false;
    }
    return true;
}
std::string octet(int numberOctet){
    std::string outputString;
    if (check_all_string()) {
        if (numberOctet == 1) {
            for (int i = 0; i < point_1; i++) {
                outputString += ipAddress[i];
            }
        } else if (numberOctet == 2) {
            for (int i = point_1 + 1; i < point_2; i++) {
                outputString += ipAddress[i];
            }
        } else if (numberOctet == 3) {
            for (int i = point_2 + 1; i < point_3; i++) {
                outputString += ipAddress[i];
            }
        } else if (numberOctet == 4) {
            for (int i = point_3 + 1; i < ipAddress.length(); i++) {
                outputString += ipAddress[i];
            }
        }
    }
    return outputString;
}
bool check_octet(int numOctet){
    std::string checkedOctet = octet(numOctet);
    int int_octet=0;
    if (checkedOctet[0] == '0' && checkedOctet.length() > 1){
        std::cout << "in " << numOctet << " octet excess zero\n";
        return false;
    }else if (checkedOctet.length() > 3){
        std::cout << "in a octet " << numOctet << " number more than 3\n";
        return false;
    }
    /*
    if (checkedOctet.length() == 3){
        int_octet += (checkedOctet[0] - '0') * 100;
        int_octet += (checkedOctet[1] - '0') * 10;
        int_octet += (checkedOctet[2] - '0');
    }else if (checkedOctet.length() == 2){
        int_octet += (checkedOctet[0] - '0') * 10;
        int_octet += (checkedOctet[1] - '0');
    }else if (checkedOctet.length() == 1) {
        int_octet += (checkedOctet[0] - '0');
    }
     */
    if (checkedOctet > "255"){
        std::cout << "octet " << numOctet << " more 255\n";
        return false;
    }
    return true;
}
int main() {
    std::cout << "for exit enter 'exit'\n";
    bool exit = false;
    while (!exit) {
        std::cout << "Please enter IP address :";
        std::cin >> ipAddress;
        if (ipAddress == "exit"){
            exit = true;
            break;
        }
        if (check_all_string()){
            bool all_octet_correct = check_octet(1) && check_octet(2) && check_octet(3) && check_octet(4);
            all_octet_correct ? std::cout << "ip address correct\n" : std::cout << "ip address not correct\n";
        }else std::cout << "ip address not correct\n";
    }
    return 0;
}