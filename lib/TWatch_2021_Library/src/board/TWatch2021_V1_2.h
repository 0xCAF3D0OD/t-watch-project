#ifndef __TWATCH2021_V1_2_H__
#define __TWATCH2021_V1_2_H__

/*
log:
1.Added RTC interrupt
2.Reduced sleep power consumption
*/

// Pin definition
#define TWATCH_PWR_ON    5

#define TWATCH_CHARGING  2
#define TWATCH_BAT_ADC   36

#define TWATCH_BTN_1     0
#define TWATCH_BTN_2     35
#define TWATCH_BTN_3     34

#define TWATCH_MOTOR     4

#define TWATCH_IICSCL    25
#define TWATCH_IICSDA    26

#define TWATCH_TOUCH_RES 33

#define TWATCH_TOUCH_INT 32
#define TWATCH_RTC_INT   32
#define TWATCH_BMA_INT_1 32
#define TWATCH_BMA_INT_2 32

#define TWATCH_AIO_INT   32

#define TFT_WIDTH        240
#define TFT_HEIGHT       240

#define TWATCH_TFT_MISO  -1
#define TWATCH_TFT_MOSI  13
#define TWATCH_TFT_SCLK  14
#define TWATCH_TFT_CS    15
#define TWATCH_TFT_DC    19
#define TWATCH_TFT_RST   27
#define TWATCH_TFT_BL    21

#endif