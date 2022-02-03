#include "tshirt.h"
#include <assert.h>

void testTshirtSize(int size_cms, char expectedSize) {
	assert(tshirtSize(size_cms) == expectedSize);
}

int main() {
	testTshirtSize(30,'\0');
	testTshirtSize(37,'S');
	testTshirtSize(38,'S');
	testTshirtSize(40,'M');
	testTshirtSize(42,'L');
	testTshirtSize(49,'\0');
	return 0;
}
