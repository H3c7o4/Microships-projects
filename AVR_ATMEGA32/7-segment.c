/**
 * 7-segment.c
 *
 * Created on: Jan 17, 2023
 *     Author: ITOK Steve Hector
 */

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_INterface.h"
#include <util/delay.h>

int main()
{
	SET_Direction(PORT_A, INPUT);
	SET_Direction_4LSB(PORT_C, OUTPUT);
	SET_Value(PORT_A, PIN_2, HIGH);
	u8 current_number = 0;

	while (1)
	{
		if (GET_Value(PORT_A, PIN_2) == LOW)
		{
			if (current_number == 9)
			{
				current_number == 0;
			}
			else
			{
				current_number++;
			}
		}
		SET_Value_4LSB(PORT_C, current_number);
		_delay_ms(250);
	}
	return 0;
}
