/***************************************************************************** *
 * ----------------------------------------------------------------------------*
 * elektronikaembedded@gamil.com ,https://elektronikaembedded.wordpress.com    *  	       	               
 * ----------------------------------------------------------------------------*
 *                                                                             *
 * File Name  : main.c                                                         *
 *                                                                             *
 * Description : main program body                                             *
 *                                                                             *
 * Version     : PrototypeV1.0                                                 *
 *                                                                             *
 * --------------------------------------------------------------------------- *
 * Authors: Sarath S                                                           *
 * Date: May 16, 2017                                                          *
 ******************************************************************************/

/* Includes -------------------------------------------------------------------*/
/* System Files */

/* MCU Files */
#include "stm32f10x.h"
#include "stm32f10x_it.h"
/* User Files */
//Low Level
#include "led.h"
#include "delay.h"
#include "debug.h"
#include "dfr0299.h"
#include "typedef.h"
//Application
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

uint8_t index;

void systemClockInit(void);

/* Private functions ---------------------------------------------------------*/

void systemClockInit(void)
{
  SysTick_Config(SystemCoreClock / 1000);
}


/* ----------------------------------------------------------------------------*
 *
 * Function Name : main
 *
 * Description   : main block
 *
 * Input : None
 *
 * Output  : None
 *
 * Return  : None
 * ----------------------------------------------------------------------------*
 * Authors : Sarath S
 * Date : May 17, 2017
 * ---------------------------------------------------------------------------*/
int main()
{
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
  systemClockInit();            /* Initialize the System Clock */
  delayInit();                  /* System Delay Initialization */
  ledInit();                    /* System Led Initialization */
  debugInit();                  /* System Serial-Debug Initialization */
  debugPutString("\r\n +-------------------------------------------------+");
  debugPutString("\r\n |               DF MiniMP3 Demo        |");
  debugPutString("\r\n +-------------------------------------------------+\r\n");
  DFR0299Init();                /* Initializing DFPlayer */
  ledSetMainLed(LED_BLINK);     /* System Led Start to Blink */
  DFSetVolume(15);              /* Set DFPlayer volume 15 */
  DFPlayFolderTrack(1,1);       /* Play Folder1 Track 1 */
  
  for(index=0;index<15;index++) /* Increase Volume DFPlayer */
  {
  DFIncreaseVolume();           
  delayms(1500);
  }
  DFPlayNextTrack();            /* Next Track DFPlayer */
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  for(index=0;index<15;index++) /* Decrease Volume DFPlayer */
  {
  DFDecreaseVolume();
  delayms(1500);
  }
  DFPause();                    /* Pause DFPlayer */
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  DFSetVolume(15);              /* Set DFPlayer volume 15 */
  DFPlayback();
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  DFPlayNextTrack();            /* Next Track DFPlayer */
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  DFPlayNextTrack();            /* Next Track DFPlayer */
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  DFPlayPreviousTrack();        /* Previous Track DFPlayer */
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  DFPlayFolderTrack(1,2);       /* Play Folder1 Track 2 */
  DFSetVolume(15);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  DFPlayFolderTrack(1,1);       /* Play Folder1 Track 1 */
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  DFPlayFolderTrack(2,1);       /* Play Folder2 Track 1 */
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  DFPlayFolderTrack(2,2);       /* Play Folder2 Track 2 */
  delayms(3000);
  delayms(3000);
  delayms(3000);
  delayms(3000);
  DFPlayThisTrack(1);           /* Play Track 1 (Folder1,Track1)*/
  while(1)
  {
    
  }
}/* End of this function */

/*******************************************************************************
			* End of file															     *
*******************************************************************************/
