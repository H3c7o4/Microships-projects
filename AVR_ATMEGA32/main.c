/**
 * main.c
 * Created on: Jan 17, 2023
 *     Author: ITOK Steve Hector
 */

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"

int main()
{
	SET_Direction(PORT_A, PIN_2, INPUT);
	SET_Direction(PORT_C, PIN_7, OUTPUT);
	SET_Value(PORT_A, PIN_2, HIGH);

	while(1)
	{
		if (GET_Value(PORT_A, PIN_2) == LOW)
		{
			SET_Value(PORT_C, PIN_7, HIGH);
		}
		else if (GET_Value(PORT_A, PIN_2) == HIGH)
		{
			SET_Value(PORT_C, PIN_7, LOW);
		}
	}
	return 0;
}
