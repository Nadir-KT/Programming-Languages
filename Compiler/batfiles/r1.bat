echo Reading Application Image ....

del  read_app.bin  
STM32_Programmer_CLI.exe -c port=SWD freq=4000 -r 0x08008000 196608 read_app.bin  
