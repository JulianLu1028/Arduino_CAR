 /*
	for Ilon wheel moving
 */


 #ifndef _Move_H__
 #define _Move_H__

 //匯入arduino核心標頭檔案
 #include "Arduino.h"
//1234567

 class MOVE
 {
    private:
      byte pin; //start pin
			

    public:

			MOVE(byte p);//建構函式
			~MOVE();//解構函式

			void forward();
			void backward();
			void right();
			void left();
			void turn_right();
			void turn_left();
			void stop();
			
			void disattach();           //釋放引腳與led的繫結
      
 };

#endif