arm-none-eabi-gcc -static -mthumb -g -mcpu=cortex-m0 *.c -T linker_script.ld -o main.elf -nostartfiles 
