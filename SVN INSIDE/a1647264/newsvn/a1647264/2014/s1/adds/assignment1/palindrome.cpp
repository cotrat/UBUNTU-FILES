#include <iostream>
#include <cstring>
using namespace std;

char* reverseString(char* revword)
{
    int length = strlen(revword);
    char* start = revword; // Points to the start of the given word
    char* end = revword + (length-1); // as above but to the end (minus 1 to avoid the end of line char)
    int i;
    char *reversed;
    reversed = new char[length];
   
   
    for(i = 0;i <= length/2; i ++) // <= is necessary to ensure the middle char is placed in an a word with an odd amount of letters
    {
        reversed[i] = *(end-i); // Setting the first value to the end
        reversed[(length-1)-i] = *(start+i);
       

    }

    return(reversed);   
}

int isPalindrome(char* word)
{
    int length = strlen(word);
    int i;
    for(i = 0;i <= length/2; i ++)
    {
        if(word[i]!=word[(length-1)-i]) // Iterating from front to middle and end to middle to see if the chars are identical
        {
            return 0;
        }
    }
    return 1;
}

void lowerCase(char* word)
{
    int length = strlen(word);
    int i;
    for(i = 0;i < length; i ++)
    {
        if((word[i] > 64) and (word[i] < 91))
        {
            word[i] = word[i] + 32; // when the char is between 65 and 90 inclusive it needs to be shifted into lower case (this is using the ASCII table)
        }
    }
}

void removeNonLetters(char* word)
{   
    int i;
    int idx = 0;
   
    int length = strlen(word);
    char *letters;
    letters = new char[length];
    for(i = 0;i <= length; i ++)
    {
        if((word[i] > 64) and (word[i] < 91)) // if a char is between this ascii range then it is a valid letter and we can move on to the next char
        {
            letters[idx] = word[i];
            idx++;
           
        }
	else if((word[i] > 96) and (word[i] < 123))
	 {
            letters[idx] = word[i];
            idx++;
           
        }
    }
    strcpy(word,letters);
	delete[] letters;
}

void encrypt(char* word)
{
    int length = strlen(word);
    int i;
    for(i = 0;i < length; i ++) // We dont want to shift the end character
    {
        if(word[i] > 119)
        {
            word[i] = word[i] - 23; // making sure words roll over correctly
        }
        else
        {   
            word[i] = word[i] + 3;
        }
    }
}

void decrypt(char* word)
{
    int length = strlen(word);
    int i;
    for(i = 0;i < length; i ++) // We dont want to shift the end character
    {
        if(word[i] > 99)
        {
            word[i] = word[i] - 3; // making sure words roll over correctly
        }
        else
        {   
            word[i] = word[i] + 23;
        }
    }
}

int main()
{
   
    char *word;
	word = new char[50];
    cin.getline(word,50);
    char ans;
    //char* wordptr = word;
    //char* returnedChar;
   

    
    cout << "The Word Was - " << word << endl;
removeNonLetters(word);
    lowerCase(word);
    word = reverseString(word);
    cout << "With all the rubbish removed & in lower case it looks like - " << word << endl;
    cout << "When reversed it looks like - " << word << endl;

    if(isPalindrome(word))
    {
        cout << "The word was a palindrome " << endl;
    }
    else
    {   
        cout << "The Word Was not a Palindrome " << endl;
    }
   
    cout << " Do you want to encrypt your word with a caeser cyper (y/n) ";
    cin >> ans;

    if(ans == 'y')
    {
        encrypt(word);
        cout << word << " Is the encrypted word " << endl;
        cout << " Do you want to now decrypt the word (y/n) ";
        cin >> ans;
        if(ans == 'y')
        {
            decrypt(word);
           	cout << word << " Is the decrypted word " << endl;

        }

    }
   delete[] word;
   
   
   
}
