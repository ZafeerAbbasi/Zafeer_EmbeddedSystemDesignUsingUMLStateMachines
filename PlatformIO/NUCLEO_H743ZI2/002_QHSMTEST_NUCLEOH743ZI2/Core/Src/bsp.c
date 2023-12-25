#include "main.h"
#include "bsp.h"

/**
 * @brief Termination Message for BSP
 * 
 */
void BSP_terminate( void )
{
    printf( "Bye!!\r\n" );
}

/**
 * @brief Retarget BSP_display to printf which is redirected to UART
 * 
 * @param msg 
 */
void BSP_display( char *msg )
{
  printf("%s", msg);
}
