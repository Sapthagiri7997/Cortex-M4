ENTRY(RESET_HANDLER)
MEMORY{
    FLASH(WRX) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM(QRX) : ORIGIN = 0x20000000, LENGTH = 128K
}

__estack = ORIGIN(RAM)+LENGTH(RAM);
SECTIONS
{
    .isr_vector:
    {
        KEEP(*(.isr_vector))
    } > FLASH
    .text:
    {
        *(.text)
        *(.rodata)
    } > FLASH
    _sidata = LOADADDR(.data);
    .data:
    {   
        _sdata=.;
        *(.data)
        _edata=.;
    } > RAM AT > FLASH
    .bss
    {
        _sbss=.;
        *(.bss)
        *(COMMON)
        _ebss=.;
    } > RAM
}