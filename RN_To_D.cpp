
#include <iostream>
#include <string>

using namespace std;


//convert from a decimal value to a string representing that number in Roman Numerals (Limited to 3999)
// assuming proper input is always given, which will be checkin in main, before running this function
// (any # from 1 - 3999 inclusive)
string convertToRomanNumeral(int decimalValue) {
    string romNumeral = "";
    int decVal = decimalValue;

    while (decVal > 0) {

        if (decVal / 1000 > 0) {                    //handle M (1000)
            romNumeral.append("M");
            decVal = decVal - 1000;
        }
        else if (decVal % 1000 > 899) {             //handle CM (900)
            romNumeral.append("CM");
            decVal = decVal - 900;
        }
        else if (decVal / 500 > 0) {                //handle D (500)
            romNumeral.append("D");
            decVal = decVal - 500;
        }
        else if (decVal % 500 > 399) {              //handle CD (400)
            romNumeral.append("CD");
            decVal = decVal - 400;
        }
        else if (decVal / 100 > 0) {                //handle C (100)
            romNumeral.append("C");
            decVal = decVal - 100;
        }
        else if (decVal % 100 > 89) {               //handle XC (90)
            romNumeral.append("XC");
            decVal = decVal - 90;
        }
        else if (decVal / 50 > 0) {                 //handle L (50)
            romNumeral.append("L");
            decVal = decVal - 50;
        }
        else if (decVal % 50 > 39) {                //handle XL (40)
            romNumeral.append("XL");
            decVal = decVal - 40;
        }
        else if (decVal / 10 > 0) {                 //handle X (10)
            romNumeral.append("X");
            decVal = decVal - 10;
        }
        else if (decVal % 10 == 9) {                //handle IX (9)
            romNumeral.append("IX");
            decVal = decVal - 9;
        }
        else if (decVal / 5 > 0) {                  //handle V (5)
            romNumeral.append("V");
            decVal = decVal - 5;
        }
        else if (decVal % 5 == 4) {                 //handle IV (4)
            romNumeral.append("IV");
            decVal = decVal - 4;
        }
        else if (decVal > 0) {
            romNumeral.append("I");                 //handle I (1)
            decVal = decVal - 1;
        }

    }

    return romNumeral;

}


// convert from a string romanNumeral to the decimal number that it represents (limited to MMMCMXCIX)
// assuming proper input is always given, which will be checkin in main, before running this function
// (only strings specifically filled with the chars I,V,X,L,C,D,M and following given rules)
int convertToDecimalNumber(string romanNumeral) {
    int decNum = 0;
    string rowNum = romanNumeral;
    string rowNumSegment = ""; // index 0 and 1 of rowNum, changed every iteration of the loop

    while (rowNum.size() > 0) {
        rowNumSegment = rowNum.substr(0, 2);

        if (rowNumSegment.at(0) == 'M') {                                      //handle M
            decNum = decNum + 1000;
            rowNum = rowNum.substr(1, rowNum.size());
        }
        else if (rowNumSegment.at(0) == 'D') {                                 //handle D
            decNum = decNum + 500;
            rowNum = rowNum.substr(1, rowNum.size());
        }
        else if (rowNumSegment.at(0) == 'C') {                                 //handle C -> CM, CD, C

            if (rowNumSegment.size() == 2 && rowNumSegment.at(1) == 'M') {                  //CM
                decNum = decNum + 900;
                rowNum = rowNum.substr(2, rowNum.size());
            }
            else if (rowNumSegment.size() == 2 && rowNumSegment.at(1) == 'D') {             //CD
                decNum = decNum + 400;
                rowNum = rowNum.substr(2, rowNum.size());
            }
            else {                                                                          //C
                decNum = decNum + 100;
                rowNum = rowNum.substr(1, rowNum.size());
            }
        }
        else if (rowNumSegment.at(0) == 'L') {                                  //handle L
            decNum = decNum + 50;
            rowNum = rowNum.substr(1, rowNum.size());
        }
        else if (rowNumSegment.at(0) == 'X') {                                  //handle X -> XC, XL, X

            if (rowNumSegment.size() == 2 && rowNumSegment.at(1) == 'C') {                  //XC
                decNum = decNum + 90;
                rowNum = rowNum.substr(2, rowNum.size());
            }
            else if (rowNumSegment.size() == 2 && rowNumSegment.at(1) == 'L') {             //XL
                decNum = decNum + 40;
                rowNum = rowNum.substr(2, rowNum.size());
            }
            else {                                                                          //X
                decNum = decNum + 10;
                rowNum = rowNum.substr(1, rowNum.size());
            }
        }
        else if (rowNumSegment.at(0) == 'V') {                                  //handle V
            decNum = decNum + 5;
            rowNum = rowNum.substr(1, rowNum.size());
        }
        else if (rowNumSegment.at(0) == 'I') {                                  //handle I -> IX, IV, I

            if (rowNumSegment.size() == 2 && rowNumSegment.at(1) == 'X') {                  //IX
                decNum = decNum + 9;
                rowNum = rowNum.substr(2, rowNum.size());
            }
            else if (rowNumSegment.size() == 2 && rowNumSegment.at(1) == 'V') {             //IV
                decNum = decNum + 4;
                rowNum = rowNum.substr(2, rowNum.size());
            }
            else {                                                                          //I
                decNum = decNum + 1;
                rowNum = rowNum.substr(1, rowNum.size());
            }
        }


    }


    return decNum;
}


// Run a few test calls of the previous functions, I verfied that everything is working properly with about 2 hours and 40 minutes to spare, so main
// will also be in charge of a interactive loop that can take user input and call the user selected functions
int main()
{

    //test calls
    cout << "3 = " << convertToRomanNumeral(3) << "\n";
    cout << "Back to decimal = " << convertToDecimalNumber(convertToRomanNumeral(3)) << "\n";
    cout << "4 = " << convertToRomanNumeral(4) << "\n";
    cout << "Back to decimal = " << convertToDecimalNumber(convertToRomanNumeral(4)) << "\n";
    cout << "9 = " << convertToRomanNumeral(9) << "\n";
    cout << "Back to decimal = " << convertToDecimalNumber(convertToRomanNumeral(9)) << "\n";
    cout << "2673 = " << convertToRomanNumeral(2673) << "\n";
    cout << "Back to decimal = " << convertToDecimalNumber(convertToRomanNumeral(2673)) << "\n";
    cout << "1224 = " << convertToRomanNumeral(1224) << "\n";
    cout << "Back to decimal = " << convertToDecimalNumber(convertToRomanNumeral(1224)) << "\n";
    cout << "3999 = " << convertToRomanNumeral(3999) << "\n"; //MMMCMXCIX = 3, 999
    cout << "Back to decimal = " << convertToDecimalNumber(convertToRomanNumeral(3999)) << "\n";

    //begin work on interactive loop for user input
    bool keepGoing = true;
    bool validChoice = true;
    char userYesOrNo = 'z';
    char userFunction = 'z'; // a = convertToRomanNumeral(int value), b = convertToDecimalNumber(string romanNumeral)
    int userNumber = 0; // 1 - 3999 inclusive
    string userRomanNumeral = ""; // only strings specifically filled with the chars I,V,X,L,C,D,M and following given rules, this will be complicated

    //begin interactive loop
    while (keepGoing) {     //loop till player quits
        cout << "Welcome to my Roman Numeral <-> Decimal converter!\n";

        while (validChoice && keepGoing) {
            cout << "type a to convert from a number to a Roman Numeral, or type b to convert from a Roman Numeral to a number\n";
            cin >> userFunction;

            if (userFunction == 'a') {                  //convertToRomanNumeral side of loop
                validChoice = true;
                cout << "Convert from a number to a Roman Numeral selected (option a)\n";
                cout << "Please enter any number ranging from 1 - 3999 inclusive\n";
                cin >> userNumber;
                while (validChoice && keepGoing) {
                    if (userNumber > 0 && userNumber < 4000) {          //valid input received
                        validChoice = true;
                        cout << "your number as a Roman Numeral is " << convertToRomanNumeral(userNumber) << "\n";
                    }
                    else {
                        validChoice = false;
                        while (validChoice == false) {                  //invalid input received
                            cout << "Invalid input!\n";
                            cout << "please enter r to retry\n";
                            cin >> userFunction;
                            if (userFunction == 'r') {
                                validChoice = true;
                            }
                        }
                    }

                    //address whether user would like to keep going or not
                    cout << "would you like to keep using this Roman Numeral <-> Decimal converter? enter y for yes or n for no\n";
                    cin >> userYesOrNo;
                    if (userYesOrNo == 'y') {
                        keepGoing = true;
                        break;
                    }
                    else if (userYesOrNo == 'n') {
                        keepGoing = false;
                        break;
                    }
                    else {
                        validChoice = false;
                        while (validChoice == false) {
                            cout << "Invalid input!\n";
                            cout << "Please enter y for yes or n for no\n";
                            cin >> userYesOrNo;
                            if (userYesOrNo == 'y' || userYesOrNo == 'n') {
                                validChoice = true;
                            }
                        }
                    }

                }// end of convertToRomanNumeral function loop

            }// option a selected ending if statement ending bracket

            else if (userFunction == 'b') {             //convertToDecimalNumber side of loop
                validChoice = true;
                cout << "Convert from a Roman Numeral to a number selected (option b)\n";
                cout << "Please enter any valid Roman Numeral (max value = MMMCMXCIX)\n";
                cout << "Note: Roman numerals do have specific rules, and I don't check for all of them, please be sure to enter it in correctly.\n";
                cout << "I only verify that all of your characters entered match one of these: I,V,X,L,C,D,M\n";
                cin >> userRomanNumeral;
                while (validChoice && keepGoing) {
                    // I,V,X,L,C,D,M = valid input
                    for (int i = 0; i < userRomanNumeral.size(); i++) {
                        if (userRomanNumeral.at(i) == 'M' || userRomanNumeral.at(i) == 'D' || userRomanNumeral.at(i) == 'C'
                            || userRomanNumeral.at(i) == 'L' || userRomanNumeral.at(i) == 'X' || userRomanNumeral.at(i) == 'V'
                            || userRomanNumeral.at(i) == 'I') {
                            validChoice = true;
                        }
                        else {
                            validChoice = false;
                        }
                    }// end of for loop to check user input

                    if (validChoice == false) {                 //invalid input received

                        validChoice = false;
                        while (validChoice == false) {
                            cout << "Invalid input!\n";
                            cout << "please enter r to retry\n";
                            cin >> userFunction;
                            if (userFunction == 'r') {
                                validChoice = true;
                            }
                        }

                        /*while (validChoice == false) {
                            cout << "Invalid input!\n";
                            cout << "Please enter any valid Roman Numeral\n";
                            cin >> userRomanNumeral;
                            for (int i = 0; i < userRomanNumeral.size(); i++) {
                                if (userRomanNumeral.at(i) == 'M' || userRomanNumeral.at(i) == 'D' || userRomanNumeral.at(i) == 'C'
                                    || userRomanNumeral.at(i) == 'L' || userRomanNumeral.at(i) == 'X' || userRomanNumeral.at(i) == 'V'
                                    || userRomanNumeral.at(i) == 'I') {
                                    validChoice = true;
                                }
                                else {
                                    validChoice = false;
                                }
                            }// run loop on new userRomanNumeral to see if it is valid or not
                        }*/
                    }
                    else {                                      //valid input received
                        validChoice = true;
                        cout << "your Roman Numeral as a number is " << convertToDecimalNumber(userRomanNumeral) << "\n";
                    }

                    //address whether user would like to keep going or not
                    cout << "would you like to keep using this Roman Numeral <-> Decimal converter? enter y for yes or n for no\n";
                    cin >> userYesOrNo;
                    if (userYesOrNo == 'y') {
                        keepGoing = true;
                        break;
                    }
                    else if (userYesOrNo == 'n') {
                        keepGoing = false;
                        break;
                    }
                    else {
                        validChoice = false;
                        while (validChoice == false) {
                            cout << "Invalid input!\n";
                            cout << "Please enter y for yes or n for no\n";
                            cin >> userYesOrNo;
                            if (userYesOrNo == 'y' || userYesOrNo == 'n') {
                                validChoice = true;
                            }
                        }
                    }



                }// end of convertToDecimalNumber function loop

            }// option b selected ending if statement ending bracket

            else {                                      //a or b not given, retry for user input
                validChoice = false;
                while (validChoice == false) {
                    cout << "Invalid input!\n";
                    cout << "please enter r to retry\n";
                    cin >> userFunction;
                    if (userFunction == 'r') {
                        validChoice = true;
                    }
                }
            }


        }// end of inner loop where user selects function they'd like to use


    }// end of interactive loop


    cout << "\n Have a great day!";
    return 0;
}


/*
Code Challenge: Decimal to Roman Numeral Converter
Last summer the archeology department excavated some ancient Roman ruins. They uncovered an old
accountant’s office in which they discovered thousands of tablets with hundreds of thousands of roman
numerals on the tablets. Upon close examination, the archeologists and their students discovered the largest
number they encountered on the tablets was MMMCMXCIX = 3,999.
Now they want to convert all the numbers from the tablets to decimal numbers. To make this conversion easier,
they commissioned you to write a program to convert roman numerals to decimal numbers and decimal
numbers back to roman numerals to check their accuracy.
There are seven basic roman numerals:
I= 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000
There are four basic rules for creating roman numerals:
1. Normally, values are combined by adding the values of the symbol together.
For example, III = 3, VII = 7, CLXV = 165.
2. Roman numerals also involve subtractive notation.
If symbol A is less than the symbol immediately following it (B), A is subtracted from B and AB is treated as a
unit to add to the total. Thus, IV = 4, XL = 40, XC = 90.
3. Subtractive notation only ever involves two symbols.
So, for example, XIV = 14, not 4, and XCIV = 94 ((V – I) + (C– X))
instead of 84 (C – X – V – I).
4. A symbol representing 10x may not precede any symbol larger than 10x+1.
For example, C cannot be preceded by I or V, only by X (or, of course, by a symbol representing a value equal
to or larger than C).

To test how well your code works you may use the calculator found at
https://numeralsconverter.com/convert-number-to-numeral/
*/