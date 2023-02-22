/*
	for arm moving
*/

#include "Arduino.h"

#include <Servo.h>


class ARM : public Servo
{
		private:
			unsigned long smt, duration;
			int read = 90, target = 90, output;
			int max , min;

		public:
			ARM(byte p, int mx, int mm);//p = pin  mx = max  mm = min
			~ARM();
			void run(int t);//t = target


}
