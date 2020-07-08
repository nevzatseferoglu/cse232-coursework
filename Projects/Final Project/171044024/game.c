#include <stdio.h>

char* matchGivenWord( char* word ,char queriedLetter );
int findNumberOfChars( char* word );
void getWord();
void reset();

int main( void ) {

    int numOfChars = 0;
    int missMatch = 0;

    char word[8] = NULL;
    char typedWord[8] = {'_' , '_' , '_', 
    '_','_' ,'_','_','_'};

    char pressedLetter = '\0';
    int start = 0;

    int i = 0;

    while ( !start ) {
        reset();
        getWord();
    }

    /* it will be sended to 7-Segment-Display */
    numOfChars = findNumberOfChars( word );

    while ( findNumberOfChars( typedWord ) != numOfChars 
        && missMatch != 10  )
    {
        scanf("%c",&pressedLetter);
        char* takenWord = matchGivenWord(word , pressedLetter);

        for( int i = 0 ; i < 8 ; ++i ) {
            if( takenWord[i] != '\0' ) {
                typedWord[i] = takenWord[i];
            }
        }

        if( findNumberOfChars(takenWord) == 0 ) {
            ++missMatch;
        }
        printWordtoScreen();
    }

    if( missMatch < 10 ) {
        printf("Win");  
    } 
    else {
        printf("Lose");
    }
    
    
    return 0;
}

void printWordtoScreen(){ /*Print the word to */}
void getWord(){ /* Get input with shifting */};
void reset(){ /* Reset all the input that's given by the player */};
int findNumberOfChars( char* word ) {
    
    int numOfChars = 0;
    for( int i = 0 ; i < 8 ; ++i ) {
        if( word[i] != '\0' ) {
            ++numOfChars;
        }
    }
    return numOfChars;
}
char* matchGivenWord( char* word ,char queriedLetter ) {

    char* matchedWord = (char*) malloc( sizeof(char) * 8);
    
    for( int i = 0 ; i < 8 ; ++i ) {
        matchedWord[i] = '\0';
    }

    for( int i = 0 ; i < 8 ; ++i ) {
        if( word[i] == queriedLetter ) {
            matchedWord[i] = queriedLetter;
        }
    }
    return matchedWord;
}