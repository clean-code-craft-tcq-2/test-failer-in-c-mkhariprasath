typedef struct {
	int PairNumber;
	char MajorColor[10];
	char MinorColor[10];
} ColorPair;

extern ColorPair *formatColorMap(ColorPair *colorPair);
extern void printColorMaponConsole(ColorPair *colorPairPtr);
extern void printColorMap(void (*fpprintColorMaponConsole)(ColorPair*));

