#include <iostream>
#include <cmath>
void test (int win_X_Column, int win_O_Column, int win_X_Str, int win_O_Str, int win_X_Diagonal,int win_O_Diagonal,int characters_X, int characters_O, bool corField){
    std::cout <<"win_X_Column "<< win_X_Column << std::endl;
    std::cout << "win_O_Column " << win_O_Column << std::endl;
    std::cout << "win_X_Str " << win_X_Str << std::endl;
    std::cout << "win_O_Str " << win_O_Str << std::endl;
    std::cout << "win_X_Diagonal " << win_X_Diagonal << std::endl;
    std::cout << "win_O_Diagonal " << win_O_Diagonal << std::endl;
    std::cout << "characters_X " << characters_X << std::endl;
    std::cout << "characters_O " << characters_O << std::endl;
    std::cout << "corField " << corField << std::endl;
}
char field_Element (std::string str1,std::string str2,std::string str3,int x,int y){
    return ( (y == 1) ? (str1[x]) : ((y == 2) ? (str2[x]) : (str3[x])) );
}

bool correct_Symbol (std::string str1,std::string str2,std::string str3){
    for (int str = 3; str > 0; str--){
        for (int sy = 2 ; sy >= 0 ; sy--){
            char symbol = (field_Element(str1,str2,str3,sy,str));
            bool corSy = (symbol == 'X' || symbol == 'O' || symbol == '.');
            if (!corSy) return false;
        }
    }
    return true;
}

int winSequence (std::string str1,std::string str2,std::string str3,char element,bool col_or_str){
    int winSequence=0;
    for (int column = !col_or_str ? 0:1; column <= (!col_or_str ? 2:3); column++) {
        for (int str = !col_or_str ? 1:0, count = 0; str <= (!col_or_str ? 3:2); str++) {
            char sy;
            if (!col_or_str){
                sy = field_Element(str1, str2, str3, column, str);
            }else sy = field_Element(str1, str2, str3, str, column);

            if (sy == element) {
                count++;
                if (count == 3) winSequence++;
            }
        }
    }

    return winSequence;
}
int winDiagonal (std::string str1,std::string str2,std::string str3, char element){
    char sy1 = field_Element(str1,str2,str3,0,1);
    char sy2 = field_Element(str1,str2,str3,1,2);
    char sy3 = field_Element(str1,str2,str3,2,3);
    char sy4 = field_Element(str1,str2,str3,2,1);
    char sy5 = field_Element(str1,str2,str3,1,2);
    char sy6 = field_Element(str1,str2,str3,0,3);
    bool diagonal1 = false;
    bool diagonal2 = false;
    if (sy1 == element && sy2 == element && sy3 == element){
        diagonal1 = true;
    }
    if (sy4 == element && sy5 == element && sy6 == element){
        diagonal2 = true;
    }
    bool diagonalBoth = (diagonal1 == true) && (diagonal2 == true);
    if (diagonalBoth){
        return 2;
    }else {
        return diagonal1 || diagonal2;
    }
}
int characters (std::string str1,std::string str2,std::string str3, char element){
    std::string allStr = str1 + str2 + str3;
    int counter=0;
    for (int i = 0; i < allStr.length(); i++){
        if (allStr[i] == element){
            counter++;
        }
    }
    return counter;
}
bool correct_Field(int colX, int colO, int strX, int strO, int diagX, int diagO, int numX, int numO, int numDot){
    if ( std::abs(numX - numO) <=1 && (colX + colO + strX +strO + diagX + diagO) <= 1){
        bool winX = ((colX + strX + diagX) == 1);
        bool winO = ((colO + strO + diagO) == 1);
        if (winX && (numX > numO)){
            return true;
        }else if (winO && (numO > numX)){
            return true;
        }else if (!winX && !winO){
            return true;
        }else return false;
    }else return false;
}
std::string winner (int colX, int colO, int strX, int strO, int diagX, int diagO, bool corField){
    bool winX = ((colX + strX + diagX) == 1);
    bool winO = ((colO + strO + diagO) == 1);
    if (winX && corField){
        return "X";
    }else if (winO && corField){
        return "O";
    }else if (!winX && !winO){
        return "null";
    }
};
int main() {
    std::string str_1;
    std::string str_2;
    std::string str_3;
    std::cout << "Enter the playing field :\n";
    std::cin >> str_1;
    std::cin >> str_2;
    std::cin >> str_3;
    //int x = 2;
    //int y = 3;
    bool corStr = (str_1.length() == 3 && str_2.length() == 3 && str_3.length() == 3);
    bool corSy = correct_Symbol(str_1,str_2,str_3);
    if (!corStr){
        std::cout << "Line length error !";
        return 0;
    }else if (!corSy){
        std::cout << "wrong character !";
        return 0;
    }
    int win_X_Column = winSequence(str_1,str_2,str_3,'X',false);
    int win_O_Column = winSequence(str_1,str_2,str_3,'O',false);
    int win_X_Str = winSequence(str_1,str_2,str_3,'X',true);
    int win_O_Str = winSequence(str_1,str_2,str_3,'O',true);
    int win_X_Diagonal = winDiagonal(str_1,str_2,str_3,'X');
    int win_O_Diagonal = winDiagonal(str_1,str_2,str_3,'O');
    int characters_X = characters(str_1,str_2,str_3,'X');
    int characters_O = characters(str_1,str_2,str_3,'O');
    int characters_Dot = characters(str_1,str_2,str_3,'.');
    bool corField = correct_Field(win_X_Column,win_O_Column,win_X_Str,win_O_Str,win_X_Diagonal,win_O_Diagonal,characters_X,characters_O,characters_Dot);
    if (false) {
        test(win_X_Column, win_O_Column, win_X_Str, win_O_Str, win_X_Diagonal, win_O_Diagonal,characters_X,characters_O,corField);
    }
    std::string win = winner(win_X_Column,win_O_Column,win_X_Str,win_O_Str,win_X_Diagonal,win_O_Diagonal,corField);
    if (corField) {
        if (win == "X") {
            std::cout << "Petya won\n";
        } else if (win == "O") {
            std::cout << "Vanya won\n";
        } else if (win == "null") {
            std::cout << "Nobody";
        }
    }else std::cout << "incorrect";

    return 0;
}
