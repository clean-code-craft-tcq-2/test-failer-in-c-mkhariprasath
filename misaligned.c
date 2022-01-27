#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const char* alignedmajorColor[] = {"White", "Red   ", "Black ", "Yellow", "Violet"};
const char* alignedminorColor[] = {"Blue  ", "Orange", "Green ", "Brown ", "Slate "};

unsigned int sep1Position = 0, sep2Position = 0;
unsigned int oldSep1Position, oldSep2Position;
bool lineNumber[25] = {0};
int currentLine = 0;

bool checkCompleteMessage()
{
    for (int i  = 0; i < 25; i++)
    {
        printf("%d",lineNumber[i]);
        if (lineNumber[i] == 1)
            return true;
        else;
    }
    return false;
}

void findSepPosition(char * str)
{
    oldSep1Position = sep1Position;
    oldSep2Position = sep1Position;
    
    char * pch = strchr(str,'|');
    if(pch!=NULL)
        sep1Position = pch-str+1;

    pch=strchr(pch+1,'|');
    if(pch!=NULL)
        sep2Position = pch-str+1;
}

bool validateSeparatorPosition(char *str)
{
    currentLine++;
    findSepPosition(str);
    if ((oldSep1Position == sep1Position) && (oldSep2Position == sep2Position))
        return true;
    else 
        lineNumber[currentLine] = true;
        return false;
}

void printColorMaponConsole(int d, const char *s1, const char *s2 ) {
    char textToBePrintedOnConsole[50];
	sprintf(textToBePrintedOnConsole, "%2d | %s | %s", d, s1, s2);
    //printf("%s\n", textToBePrintedOnConsole);
    validateSeparatorPosition(textToBePrintedOnConsole);

    //printf("%s\n",textToBePrintedOnConsole);

}

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int fakePrintColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printColorMaponConsole(i * 5 + j, majorColor[i], minorColor[i]);
            //printColorMaponConsole(i * 5 + j, alignedminorColor[i], alignedminorColor[i]);
        }
    }

    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    fakePrintColorMap();
    bool isMisaligned = checkCompleteMessage();
    assert(isMisaligned == false);
    printf("All is well (maybe!)\n");
    return 0;
}
