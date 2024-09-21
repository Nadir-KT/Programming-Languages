echo Flashing Image ...

STM32_Programmer_CLI.exe -c port=SWD freq=4000 -w app.bin  0x08008000 -HardRst

