
# TouchGFX application with Logger on STM32F429 Disco Board

This project includes TouchGFX application and Logger fucntionality using FreeRTOS Utilities.

#### * GUI application code base has been generated using STM TouchGFX software and further updations has been done according to application. *

GUI applications contains following:
1. Start screen with an Analog Clock to show time
2. Home screen with a wallpaper and a Digital clock

> User can swicth between two screens using touch buttons available on screen or using the sliding gesture.

Others tasks which application is doing are as follows:
1. Led blinking
2. Logging activities using Logger class which uses UART in DMA mode to transmit data
3. Logging Test tasks which tests the Logger functionality with other running tasks


As TouchGFX code uses FreeRTOS as RTOS platform other activities are also based on RTOS platform.


What you can learn out of it?? Follow through:
1. Creating GUI tasks using TouchGFX and updating it according to custom application
2. Creating project in C++ environment using FreeRTOS Utilities
3. Synchronizing multiple tasks to build an RTOS based application

etc..


Using C++ class function in C source document -> https://github.com/embeddedcrab/STM32F429_Disco/blob/master/Using_C%2B%2B_ClassFunction_in%20_C.pdf
Video Link -> https://github.com/embeddedcrab/STM32F429_Disco/blob/master/VID_20200609_124605.mp4


Explore for more, you might find your needed stuff!


Happy to Help and Share 😊
Cheers!
