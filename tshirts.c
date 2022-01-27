#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(38) == 'S');//size 38 is undefined size
    assert(size(-38) == 'S'); //size is a unsigned integer, doesnot cover the negative inputs
    assert(size(40) == 'M');
    assert(size(42) == 'M'); //Size 42 is undefined size
    assert(size(43) == 'L');
    assert(size(29) != 'S'); //No Small size lower limit is specified, unbounded input range
    assert(size(43) != 'L'); //No Large size higher limit is specified, unbounded input range
    printf("All is well (maybe!)\n");
    return 0;
}
