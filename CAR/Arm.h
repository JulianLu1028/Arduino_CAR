/*
	for arm moving
*/

#include "Arduino.h"

#include <Servo.h>


class ARM : public Servo
{
		private:
			unsigned long smt, duration;
			int angle_read = 90, target = 90, output;
			int max , min;

		public:
			ARM();
			~ARM();
      int link(byte p, int mx, int mm);//p = pin  mx = max  mm = min
			int run(int t);//t = target



};
