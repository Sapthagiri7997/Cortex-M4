extern unsigned int _sdata
extern unsigned int _edata
extern unsigned int _sbss
extern unsigned int _ebss
extern unsigned int _estack
void Defalut_handler(void){
    while(1);
}
void NMI_Handler(void) __attribute__((weak,alias("Default_handler")));
void Hardfault_Handler(void) __attribute__((weak,alias("Default_handler")));
void Usage_Handler(void) __attribute__((weak,alias("Default_handler")));
void Memage_Handler(void) __attribute__((weak,alias("Default_handler")));
void Bus_Handler(void) __attribute__((weak,alias("Default_handler")));
void SVC_Handler(void) __attribute__((weak,alias("Default_handler")));
void Pendsv_Handler(void) __attribute__((weak,alias("Default_handler")));
void Systick_handler(void) __attribute__((weak,alias("Default_handler")));

void Reset_Handler(void){
    unsigned int *src;
    unsigned int *dst;
    src=_sidata;
    dst=_sdata;
    while(dst<&_edata){
        *dst++=*src++;
    }
}
__attribute__((.isr_vector)) vector[]={
    
}