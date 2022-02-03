ENTRY(Reset_Handler)
MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x00040000
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000
}

SECTIONS
{
    .text :
    {
        _text = .;
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    _loadaddress_data = LOADADDR(.data);
    .data :
    {
        _data = .;
        _ldata = LOADADDR (.data);
        *(vtable)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > SRAM AT> FLASH

    .bss :
    {
        _bss = .;
        __bss_start__ = _bss;
        *(.bss*)
        . = ALIGN(4);
        *(COMMON)
        _ebss = .;
        __bss_end__ = _ebss;
        . = ALIGN(4);
        _exit = .;
    } > SRAM
}