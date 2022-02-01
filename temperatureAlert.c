#include <stdio.h>
#include "temperatureAlert.h"

int alertFailureCount = 0;

void networkAlertFailureCheck(int returnCode) {
	if (returnCode != 200) {
		alertFailureCount += 1;
    }
}

float farenheitToCelciusConvertor (float farenheit) {
	float celcius = (farenheit - 32) * 5 / 9;
	return celcius;
}

void alertInCelcius(float farenheit, int (*fpNetworkAlert) (float)) {
	float celcius = farenheitToCelciusConvertor(farenheit);
	int returnCode = (*fpNetworkAlert)(celcius);
	networkAlertFailureCheck(returnCode);
}

