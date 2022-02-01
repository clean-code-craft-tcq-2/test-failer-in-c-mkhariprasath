#include <stdio.h>
#include "tShirtTester.h"

char tshirtSize(int size_cms) {
    char sizeName = '\0';
    if(size_cms > MIN_S_SIZE &&
			size_cms <= MAX_S_SIZE) {
        sizeName = 'S';
    } else if(size_cms > MIN_M_SIZE &&
			size_cms < MAX_M_SIZE) {
        sizeName = 'M';
    } else if(size_cms >= MIN_L_SIZE &&
			size_cms < MAX_L_SIZE) {
        sizeName = 'L';
    } else {
	}
    return sizeName;
}

