#include <stdio.h>

typedef struct {
	int PairNumber;
	char MajorColor[10];
	char MinorColor[10];
} ColorPair;

extern ColorPair *formatColorMap(ColorPair *colorPair);
extern void printColorMaponConsole(ColorPair *colorPairPtr);
extern void printColorMap(void (*fpprintColorMaponConsole)(ColorPair*));



const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

ColorPair* colorPairPtr;

int numberOfMajorColors =
sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

int GetNumberOfColorPair(){
	int NumberOfColorPair = numberOfMajorColors * numberOfMinorColors;
	return  NumberOfColorPair;
}

ColorPair *formatColorMap(ColorPair *colorPair){
	int MinorColorIndex, MajorColorIndex, ColorPairIndex=0;
	for (MajorColorIndex=0; MajorColorIndex<numberOfMajorColors; MajorColorIndex++){
		for (MinorColorIndex=0; MinorColorIndex<numberOfMinorColors; MinorColorIndex++){
			colorPair[ColorPairIndex].PairNumber = (MajorColorIndex * numberOfMinorColors) + (MinorColorIndex+1) ;	
			sprintf(colorPair[ColorPairIndex].MajorColor, "%s", MajorColorNames[MajorColorIndex]);
			sprintf(colorPair[ColorPairIndex].MinorColor, "%s", MinorColorNames[MinorColorIndex]);
			ColorPairIndex++;
		}
	}
	return colorPair;
}

void printColorMap(void (*fpprintColorMaponConsole)(ColorPair*)){
	int NumberOfColorPair = GetNumberOfColorPair();
	ColorPair colorPair[NumberOfColorPair];
	colorPairPtr = formatColorMap(colorPair);
	(*fpprintColorMaponConsole)(colorPairPtr);
}

void printColorMaponConsole(ColorPair *colorPairPtr) {
	 int NumberOfColorPair = GetNumberOfColorPair();
     int ColorPairIndex;
     printf(" |Pair Number|Major Color|Minor Color | \n");
     for (ColorPairIndex=0; ColorPairIndex<NumberOfColorPair; ColorPairIndex++){
         printf("    %d          %s          %s     \n",
              colorPairPtr[ColorPairIndex].PairNumber, colorPairPtr[ColorPairIndex].MajorColor,
				colorPairPtr[ColorPairIndex].MinorColor);
    }
}



