echo Reading Boot Loader Image ...

del read_boot.bin
STM32_Programmer_CLI.exe -c port=SWD freq=4000 -r 0x08000000 0x8000 read_boot.bin  
