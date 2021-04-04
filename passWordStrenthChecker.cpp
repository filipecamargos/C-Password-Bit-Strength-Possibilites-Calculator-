#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

/************************************************************
* Description:
*   This program prompts the user for his password. With this 
*   string, determine how many combinations of passwords 
*   exist in this set and finally, determine the bit 
*   equivalence based on the number of combinations.
* Author:
*    Filipe Ferreira
** **********************************************************/

/************************************************************
 * Prompt the user for the password and return it
 * **********************************************************/
string getPassword()
{

    string passWord = "";

    cout << "Please enter the password: ";
    getline(cin, passWord);
    
    return passWord;
}

/************************************************************
 * Takes the password as a parameter and based on it return 
 * the possible number to be used as strength 
 * **********************************************************/
void getUsedCharacterLevel(string passWord, int passWordSize, int usedCharacterLevel[], int uCLevelSize)
{
    //Check what is in the password and assign to the array values assigned
    for (int i = 0; i < passWordSize; i++) {

        //if it is a number set index 0
        if (isdigit(passWord[i])) { usedCharacterLevel[0] = 10;}

        //if it is upper cased set the index 1
        if (isupper(passWord[i])) { usedCharacterLevel[1] = 26;}

        //if it is lower cased set the index 2
        if (islower(passWord[i])) { usedCharacterLevel[2] = 26;}

        //if it is a symbol cased set the index 3
        if (!isdigit(passWord[i]) && !isupper(passWord[i]) && !islower(passWord[i]))
        {
            usedCharacterLevel[3] = 32;
        }
    }
}

/********************************************************************
 * Determine the number of the possibilities in the password
 * Takes the sum in array of characterLevels and password size = caculate
 * *******************************************************************/
long long getpassWordPossibilities(int sum, int passWordSize) {

    //Get the streght possibilities
    return floor(pow(sum, passWordSize));
}

/********************************************************************
 * Determine the strength of the password in bites
 * Takes the sum in array of characterLevels and password size = caculate
 * *******************************************************************/
long long getpassWordstrength(int sum, int passWordSize){
    
    //Get the streght in bit
    return floor(log2(pow(sum, passWordSize)));
}

/**********************************************************
 * Display the results
 * ********************************************************/
void displayResult(long long combinations, long long bits) {
    
    //Display the combinations
    cout << "   There are ";
    cout << fixed << combinations;
    cout << " combinations!";
    cout << "\n";

    //Display the bit Strength
    cout << "   That is equivalent to a key of ";
    cout << bits;
    cout << " bits!";
}

/***********************************************************
 * HELP METHOD : Determine the sum of Array
 * *********************************************************/
int arraySum(int array[], int size)
{
    //Get the sum of all
    int sum = 0;

    for (int i = 0; i < size; i ++) {
        sum += array[i];
    }

    return sum;
}

/***********************************************************
 * This will be our drive function which will make the calls
 * to properly execute the program, prompt the user, and 
 * call the methods to caculate and display the value 
************************************************************/
int main()
{
    //Store the password
    string passWord = "";

    //caracher possibility in the passWord number 0 | uppers 1 | lowers 2 | symbol 3  
    int usedCharacterLevel[] = {0, 0, 0, 0};
    int uCLevelSize = (sizeof(usedCharacterLevel)/sizeof(*usedCharacterLevel));

    //Store the number of possibilites
    long long passWordPossibilities = 0;
    //Store the strength
    long long passWordstrength = 0;

    //Prompt for the passoword
    passWord = getPassword();
    int passWordSize = passWord.length();

    //Check the case wich the password is applied and populate the usedCharacterLevel with the possibilities
    getUsedCharacterLevel(passWord, passWordSize, usedCharacterLevel, uCLevelSize);

    //Get the sum of the determine caracher level used in the array
    int sum = arraySum(usedCharacterLevel, uCLevelSize);

    //Get the possibilities and the strength
    passWordPossibilities = getpassWordPossibilities(sum, passWordSize);
    passWordstrength = getpassWordstrength(sum, passWordSize);

    //Display the result
    displayResult(passWordPossibilities, passWordstrength);
}