

extern float farenheitToCelciusConvertor (float farenheit);
extern void alertInCelcius(float farenheit, int (*fpNetworkAlert) (float));
extern int alertFailureCount;
void networkAlertFailureCheck(int returnCode); 

#define TEMP_THRESHOLD_CELCIUS 175
