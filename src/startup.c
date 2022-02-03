#include <stdint.h>


#define SRAM_START  0x20000000U
#define SRAM_END    0x3FFFFFFF
#define SRAM_SIZE   ((SRAM_END ) - (SRAM_START))

#define STACK_START SRAM_END

int main (void);
void __libc_init_array(void);

/**
 * @brief Interrupt List
 * 
 */
void Reset_Handler(void);
void NMI_Handler(void)                      __attribute__((weak,alias("Default_Handler")));
void Hard_Fault(void)                       __attribute__((weak,alias("Default_Handler")));

/**
 * @brief Don't forget to rewrite the function as the name of Handler and
 * NameOfHandler __attribute__((weak,alias("Default_Handler")));
 * 
 */
void Default_Handler(void);


/**
 * @brief Vector table must be placed at the bening of memory
 * 
 */
uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
    STACK_START,
    (uint32_t)&Reset_Handler,                       // The reset handler
    (uint32_t)&NMI_Handler,                         // The NMI handler
    (uint32_t)&Hard_Fault,                          // The hard fault handler
    (uint32_t)&Default_Handler,                     // The MPU fault handler
    (uint32_t)&Default_Handler,                     // The bus fault handler
    (uint32_t)&Default_Handler,                     // The usage fault handler
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    (uint32_t)&Default_Handler,                     // SVCall handler
    (uint32_t)&Default_Handler,                     // Debug monitor handler
    0,                                              // Reserved
    (uint32_t)&Default_Handler,                     // The PendSV handler
    (uint32_t)&Default_Handler,                     // The SysTick handler
    (uint32_t)&Default_Handler,                     // GPIO Port A
    (uint32_t)&Default_Handler,                     // GPIO Port B
    (uint32_t)&Default_Handler,                     // GPIO Port C
    (uint32_t)&Default_Handler,                     // GPIO Port D
    (uint32_t)&Default_Handler,                     // GPIO Port E
    (uint32_t)&Default_Handler,                     // UART0 Rx and Tx
    (uint32_t)&Default_Handler,                     // UART1 Rx and Tx
    (uint32_t)&Default_Handler,                     // SSI0 Rx and Tx
    (uint32_t)&Default_Handler,                     // I2C0 Master and Slave
    (uint32_t)&Default_Handler,                     // PWM Fault
    (uint32_t)&Default_Handler,                     // PWM Generator 0
    (uint32_t)&Default_Handler,                     // PWM Generator 1
    (uint32_t)&Default_Handler,                     // PWM Generator 2
    (uint32_t)&Default_Handler,                     // Quadrature Encoder 0
    (uint32_t)&Default_Handler,                     // ADC Sequence 0
    (uint32_t)&Default_Handler,                     // ADC Sequence 1
    (uint32_t)&Default_Handler,                     // ADC Sequence 2
    (uint32_t)&Default_Handler,                     // ADC Sequence 3
    (uint32_t)&Default_Handler,                     // Watchdog timer
    (uint32_t)&Default_Handler,                     // Timer 0 subtimer A
    (uint32_t)&Default_Handler,                     // Timer 0 subtimer B
    (uint32_t)&Default_Handler,                     // Timer 1 subtimer A
    (uint32_t)&Default_Handler,                     // Timer 1 subtimer B
    (uint32_t)&Default_Handler,                     // Timer 2 subtimer A
    (uint32_t)&Default_Handler,                     // Timer 2 subtimer B
    (uint32_t)&Default_Handler,                     // Analog Comparator 0
    (uint32_t)&Default_Handler,                     // Analog Comparator 1
    (uint32_t)&Default_Handler,                     // Analog Comparator 2
    (uint32_t)&Default_Handler,                     // System Control (PLL, OSC, BO)
    (uint32_t)&Default_Handler,                     // FLASH Control
    (uint32_t)&Default_Handler,                     // GPIO Port F
    (uint32_t)&Default_Handler,                     // GPIO Port G
    (uint32_t)&Default_Handler,                     // GPIO Port H
    (uint32_t)&Default_Handler,                     // UART2 Rx and Tx
    (uint32_t)&Default_Handler,                     // SSI1 Rx and Tx
    (uint32_t)&Default_Handler,                     // Timer 3 subtimer A
    (uint32_t)&Default_Handler,                     // Timer 3 subtimer B
    (uint32_t)&Default_Handler,                     // I2C1 Master and Slave
    (uint32_t)&Default_Handler,                     // Quadrature Encoder 1
    (uint32_t)&Default_Handler,                     // CAN0
    (uint32_t)&Default_Handler,                     // CAN1
    0,                                              // Reserved
    0,                                              // Reserved
    (uint32_t)&Default_Handler,                     // Hibernate
    (uint32_t)&Default_Handler,                     // USB0
    (uint32_t)&Default_Handler,                     // PWM Generator 3
    (uint32_t)&Default_Handler,                     // uDMA Software Transfer
    (uint32_t)&Default_Handler,                     // uDMA Error
    (uint32_t)&Default_Handler,                     // ADC1 Sequence 0
    (uint32_t)&Default_Handler,                     // ADC1 Sequence 1
    (uint32_t)&Default_Handler,                     // ADC1 Sequence 2
    (uint32_t)&Default_Handler,                     // ADC1 Sequence 3
    0,                                              // Reserved
    0,                                              // Reserved
    (uint32_t)&Default_Handler,                     // GPIO Port J
    (uint32_t)&Default_Handler,                     // GPIO Port K
    (uint32_t)&Default_Handler,                     // GPIO Port L
    (uint32_t)&Default_Handler,                     // SSI2 Rx and Tx
    (uint32_t)&Default_Handler,                     // SSI3 Rx and Tx
    (uint32_t)&Default_Handler,                     // UART3 Rx and Tx
    (uint32_t)&Default_Handler,                     // UART4 Rx and Tx
    (uint32_t)&Default_Handler,                     // UART5 Rx and Tx
    (uint32_t)&Default_Handler,                     // UART6 Rx and Tx
    (uint32_t)&Default_Handler,                     // UART7 Rx and Tx
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    (uint32_t)&Default_Handler,                     // I2C2 Master and Slave
    (uint32_t)&Default_Handler,                     // I2C3 Master and Slave
    (uint32_t)&Default_Handler,                     // Timer 4 subtimer A
    (uint32_t)&Default_Handler,                     // Timer 4 subtimer B
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    (uint32_t)&Default_Handler,                     // Timer 5 subtimer A
    (uint32_t)&Default_Handler,                     // Timer 5 subtimer B
    (uint32_t)&Default_Handler,                     // Wide Timer 0 subtimer A
    (uint32_t)&Default_Handler,                     // Wide Timer 0 subtimer B
    (uint32_t)&Default_Handler,                     // Wide Timer 1 subtimer A
    (uint32_t)&Default_Handler,                     // Wide Timer 1 subtimer B
    (uint32_t)&Default_Handler,                     // Wide Timer 2 subtimer A
    (uint32_t)&Default_Handler,                     // Wide Timer 2 subtimer B
    (uint32_t)&Default_Handler,                     // Wide Timer 3 subtimer A
    (uint32_t)&Default_Handler,                     // Wide Timer 3 subtimer B
    (uint32_t)&Default_Handler,                     // Wide Timer 4 subtimer A
    (uint32_t)&Default_Handler,                     // Wide Timer 4 subtimer B
    (uint32_t)&Default_Handler,                     // Wide Timer 5 subtimer A
    (uint32_t)&Default_Handler,                     // Wide Timer 5 subtimer B
    (uint32_t)&Default_Handler,                     // FPU
    0,                                              // Reserved
    0,                                              // Reserved
    (uint32_t)&Default_Handler,                     // I2C4 Master and Slave
    (uint32_t)&Default_Handler,                     // I2C5 Master and Slave
    (uint32_t)&Default_Handler,                     // GPIO Port M
    (uint32_t)&Default_Handler,                     // GPIO Port N
    (uint32_t)&Default_Handler,                     // Quadrature Encoder 2
    0,                                              // Reserved
    0,                                              // Reserved
    (uint32_t)&Default_Handler,                     // GPIO Port P (Summary or P0)
    (uint32_t)&Default_Handler,                     // GPIO Port P1
    (uint32_t)&Default_Handler,                     // GPIO Port P2
    (uint32_t)&Default_Handler,                     // GPIO Port P3
    (uint32_t)&Default_Handler,                     // GPIO Port P4
    (uint32_t)&Default_Handler,                     // GPIO Port P5
    (uint32_t)&Default_Handler,                     // GPIO Port P6
    (uint32_t)&Default_Handler,                     // GPIO Port P7
    (uint32_t)&Default_Handler,                     // GPIO Port Q (Summary or Q0)
    (uint32_t)&Default_Handler,                     // GPIO Port Q1
    (uint32_t)&Default_Handler,                     // GPIO Port Q2
    (uint32_t)&Default_Handler,                     // GPIO Port Q3
    (uint32_t)&Default_Handler,                     // GPIO Port Q4
    (uint32_t)&Default_Handler,                     // GPIO Port Q5
    (uint32_t)&Default_Handler,                     // GPIO Port Q6
    (uint32_t)&Default_Handler,                     // GPIO Port Q7
    (uint32_t)&Default_Handler,                     // GPIO Port R
    (uint32_t)&Default_Handler,                     // GPIO Port S
    (uint32_t)&Default_Handler,                     // PWM 1 Generator 0
    (uint32_t)&Default_Handler,                     // PWM 1 Generator 1
    (uint32_t)&Default_Handler,                     // PWM 1 Generator 2
    (uint32_t)&Default_Handler,                     // PWM 1 Generator 3
    (uint32_t)&Default_Handler                      // PWM 1 Fault
};

void Default_Handler(void)
{

}

//variables to access the boundiries of memmory
extern uint32_t _etext;
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _loadaddress_data;
extern uint32_t _bss;
extern uint32_t _ebss;


void Reset_Handler(void)
{
    // copy .data setion to SRAM
    uint32_t size = ((uint32_t)&_edata - (uint32_t)&_data);
    uint8_t *pDst = (uint8_t*)&_data;           //sram
    uint8_t *pSrc = (uint8_t*)&_loadaddress_data;          //flash



    for (uint32_t i = 0; i < size; i++)
    {
        *pDst++ = *pSrc++;
    }
    
    // Init the .bss section to zero in SRAM
    size = (uint32_t*)&_ebss -(uint32_t*)&_bss; 
    pDst = (uint8_t*)&_bss;
    
    for (uint32_t i = 0; i < size; i++)
    {
        *pDst++ = 0;
    }
    
    //libc_initialization__
    __libc_init_array();
    //call main()
    main();
}