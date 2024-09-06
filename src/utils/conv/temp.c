#include "temp.h"


#define KELVIN_C_DELTA	273.15


float fahrenheit_to_celsius(float temp)
{
	return 5 * (temp - 32) / 9;
}


float celsius_to_fahrenheit(float temp)
{
	return 32 + (temp * 9 / 5);
}


float kelvin_to_celsius(float temp)
{
	return temp - KELVIN_C_DELTA;
}


float celsius_to_kelvin(float temp)
{
	return KELVIN_C_DELTA + temp;
}


float kelvin_to_fahrenheit(float temp)
{
	return celsius_to_fahrenheit(kelvin_to_celsius(temp));
}


float fahrenheit_to_kelvin(float temp)
{
	return celsius_to_kelvin(fahrenheit_to_celsius(temp));
}


void test_temp_conversions()
{
	float f, c, k;

	f = 100;
	c = fahrenheit_to_celsius(f);
	printf("F:%.1f => C:%.1f\n", f, c);

	f = celsius_to_fahrenheit(c);
	printf("C:%.1f => F:%.1f\n", c, f);

	k = celsius_to_kelvin(c);
	printf("C:%.1f => K:%.1f\n", c, k);

	f = kelvin_to_fahrenheit(k);
	printf("K:%.1f => F:%.1f\n", k, f);

	k = fahrenheit_to_kelvin(f);
	printf("F:%.1f => K:%.1f\n", f, k);

	c = kelvin_to_celsius(k);
	printf("K:%.1f => C:%.1f\n", k, c);
}