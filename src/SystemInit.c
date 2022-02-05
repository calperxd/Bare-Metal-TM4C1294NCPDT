#include <stdio.h>
#include "tm4c1294ncpdt.h"
#include <stdint.h>


// 		Write the SYSCTL_PLLFREQ0_R and SYSCTL_PLLFREQ1_R registers with the values of
//    Q, N, MINT, and MFRAC to configure the desired VCO frequency setting.
//    ************
//    The datasheet implies that the VCO frequency can go as high as 25.575 GHz
//    with MINT=1023 and a 25 MHz crystal.  This is clearly unreasonable.  For lack
//    of a recommended VCO frequency, this program sets Q, N, and MINT for a VCO
//    frequency of 480 MHz with MFRAC=0 to reduce jitter.  To run at a frequency
//    that is not an integer divisor of 480 MHz, change this section.
//    fVC0 = (fXTAL/(Q + 1)/(N + 1))*(MINT + (MFRAC/1,024))
//    fVCO = 480,000,000 Hz (arbitrary, but presumably as small as needed)
#define FXTAL 25000000  // fixed, this crystal is soldered to the Connected Launchpad
#define Q            0
#define N            4  // chosen for reference frequency within 4 to 30 MHz
#define MINT        96  // 480,000,000 = (25,000,000/(0 + 1)/(4 + 1))*(96 + (0/1,024))
#define MFRAC        0  // zero to reduce jitter
#define PSYSDIV 		 3

//    SysClk = fVCO / (PSYSDIV + 1)
#define SYSCLK (FXTAL/(Q+1)/(N+1))*(MINT+MFRAC/1024)/(PSYSDIV+1)

static void SystemInit(void)
{

    SYSCTL_MOSCCTL_R &= ~(SYSCTL_MOSCCTL_NOXTAL);
		SYSCTL_MOSCCTL_R &= ~(SYSCTL_MOSCCTL_PWRDN);
		while(!(SYSCTL_RIS_R & SYSCTL_RIS_MOSCPUPRIS));
		SYSCTL_RSCLKCFG_R |= SYSCTL_RSCLKCFG_OSCSRC_MOSC;
		SYSCTL_RSCLKCFG_R = (SYSCTL_RSCLKCFG_R&~SYSCTL_RSCLKCFG_PLLSRC_M)+SYSCTL_RSCLKCFG_PLLSRC_MOSC;
		SYSCTL_DSCLKCFG_R = (SYSCTL_DSCLKCFG_R&~SYSCTL_DSCLKCFG_DSOSCSRC_M)+SYSCTL_DSCLKCFG_DSOSCSRC_MOSC;
		// MFRAC = 0 and MINT to put a new value
 		SYSCTL_PLLFREQ0_R &= ~((SYSCTL_PLLFREQ0_MFRAC_M | SYSCTL_PLLFREQ0_MINT_M));
		// MINT = 96
		SYSCTL_PLLFREQ0_R |= ((1<<6)|(1<<5));
		// Q = 0 and N = 0
		SYSCTL_PLLFREQ1_R &= ~((1<<12)|(1<<11)|(1<<10)|(1<<9)|(1 << 8)|(1 << 4) | \
													(1 << 3) | (1 << 2) | (1 << 1) | (1 << 0));
		// N = 0x4
		SYSCTL_PLLFREQ1_R |= (1 << 2);
		// Turn on PLL
		SYSCTL_PLLFREQ0_R |= (1 << 23);
		// lock in register changes
		SYSCTL_RSCLKCFG_R |= SYSCTL_RSCLKCFG_NEWFREQ;      
		SYSCTL_MEMTIM0_R 	&= ~(	\
/*EBCHT*/										(1 << 25) | (1 << 24) | (1 << 23) | (1 << 22) |\
/*EBCE*/										(1 << 21)	|\
/*EWS*/											(1 << 19) | (1 << 18) | (1 << 17) |(1 << 16) |\
/*FBCHT*/										(1 << 9) | (1 << 8) | (1 << 7) | (1 << 6) |\
/*FBCE*/										(1 << 5) |\
/*FWS*/											(1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
														);
	
			SYSCTL_MEMTIM0_R 	|= (	\
/*EBCHT*/										(1 << 24) | (1 << 23) |\
/*EWS*/											(1 << 18) | (1 << 16) |\
/*FBCHT*/										(1 << 8) | (1 << 7) |\
/*FWS*/											(1 << 2) | (1 << 0)
														);
		// Wait PLL powered and locked
		while(!(SYSCTL_PLLSTAT_R & SYSCTL_PLLSTAT_LOCK));
		// 9)Write the SYSCTL_RSCLKCFG_R register's PSYSDIV value, set the USEPLL bit to
		//   enabled, and set the MEMTIMU bit.
		SYSCTL_RSCLKCFG_R = (SYSCTL_RSCLKCFG_R&~SYSCTL_RSCLKCFG_PSYSDIV_M)+(PSYSDIV&SYSCTL_RSCLKCFG_PSYSDIV_M) | SYSCTL_RSCLKCFG_MEMTIMU | SYSCTL_RSCLKCFG_USEPLL;
    return ;
}
