/*-----------------------------------------------------------------------------------------------------
【平    台】龙邱K60核心板-智能车板
【编    写】LQ-005
【E-mail  】chiusir@163.com
【软件版本】V1.0，龙邱开源代码，仅供参考，后果自负
【最后更新】2019年04月02日
【网    站】http://www.lqist.cn
【淘宝店铺】http://shop36265907.taobao.com
【编译平台】IAR 8.2
【功    能】
【注意事项】
-------------------------------------------------------------------------------------------------------*/
#include "include.h"
#include "LQ_ADC.h"
/*------------------------------------------------------------------------------------------------------
【函    数】ADC_Get
【功    能】获取龙邱母板上的11路ADC值
【参    数】num ： 0 ~ 10
【返 回 值】ADC读取的值
【实    例】ADC_Get(0);         //获取AD0接口的值
【注意事项】ADC1_SE10 =10,       // PTB4      母板上的AD0      
            ADC1_SE11 =11,       // PTB5      母板上的AD1
            ADC1_SE12 =12,       // PTB6      母板上的AD2
            ADC1_SE13 =13,       // PTB7      母板上的AD3
            ADC1_SE14 =14,       // PTB10     母板上的AD4
            ADC1_SE15 =15,       // PTB11     母板上的AD5
            ADC1_SE16 =16,       // ADC1_SE16 母板上的AD6
            ADC0_SE16 =16,       // ADC0_SE16 母板上的AD7
            ADC0_SE11 =11,       // PTA8      母板上的AD8
--------------------------------------------------------------------------------------------------------*/
uint16_t ADC_Get(uint8_t num)
{
    switch(num)
    {
      case 0:
        return  ADC_Mid(ADC1, ADC0_SE8, ADC_12bit);
        break;
        
      case 1:
        return  ADC_Mid(ADC1, ADC0_SE9, ADC_12bit);
        break;
        
      case 2:
        return  ADC_Mid(ADC1, ADC0_SE12, ADC_12bit);
        break;
        
      case 3:
        return  ADC_Mid(ADC1, ADC0_SE13, ADC_12bit);
        break;
        
      case 4:
        return  ADC_Mid(ADC1, ADC1_SE10, ADC_12bit);
        break;
        
      case 5:
        return ADC_Mid(ADC1, ADC1_SE11, ADC_12bit);
        break;
        
      case 6:
        return  ADC_Mid(ADC1, ADC1_SE12, ADC_12bit);
        break;
        
      case 7:
        return  ADC_Mid(ADC1, ADC1_SE13, ADC_12bit);
        break;
        
      
        
        
      default:
        return 0;   
    }
}



/*------------------------------------------------------------------------------------------------------
【函    数】Test_ADC
【功    能】测试母板上的10路ADC接口
【参    数】无
【返 回 值】无
【实    例】Test_ADC(); //打印并显示电压
【注意事项】
--------------------------------------------------------------------------------------------------------*/
#ifdef LQ_OLED
void Test_ADC(void)
{
    LED_Init();
    KEY_Init();
    UART_Init(UART4, 115200);
    
    ADC_Init(ADC0);
    ADC_Init(ADC1);
    
    OLED_Init();
    OLED_CLS();
    printf("ADC 测试例程");
     printf("ADC1_SE13 =13,       // PTB7      母板上的AD3\n ");
    printf("ADC1_SE14 =14,       // PTB10     母板上的AD4\n ");
    
    
    uint16_t batv0 = (uint16_t)(ADC_Get(0)*0.806);
    uint16_t batv1 = (uint16_t)(ADC_Get(1)*0.806);
    uint16_t batv2 = (uint16_t)(ADC_Get(2)*0.806);
    uint16_t batv3 = (uint16_t)(ADC_Get(3)*0.806);
    uint16_t batv4 = (uint16_t)(ADC_Get(4)*0.806);
    uint16_t batv5 = (uint16_t)(ADC_Get(5)*0.806);
    uint16_t batv6 = (uint16_t)(ADC_Get(6)*0.806);
    uint16_t batv7 = (uint16_t)(ADC_Get(7)*0.806);
    uint16_t batv8 = (uint16_t)(ADC_Get(8)*0.806);

    uint8_t key = 0;
    char txt[16];
    while(1)
    {
        /* 获取 ADC通道值 */
        batv0 = (uint16_t)(ADC_Get(0)*0.806);
        batv1 = (uint16_t)(ADC_Get(1)*0.806);
        batv2 = (uint16_t)(ADC_Get(2)*0.806);
        batv3 = (uint16_t)(ADC_Get(3)*0.806);
        batv4 = (uint16_t)(ADC_Get(4)*0.806);
        batv5 = (uint16_t)(ADC_Get(5)*0.806);
        batv6 = (uint16_t)(ADC_Get(6)*0.806);
        batv7 = (uint16_t)(ADC_Get(7)*0.806);
        batv8 = (uint16_t)(ADC_Get(8)*0.806);
          
        switch(KEY_Read(1))     //按键按下翻页
        {
          case 1:
            OLED_CLS();          //LCD清屏
            key = 0;            //K0 按下 第一页
            break;           
          case 2: 
            OLED_CLS();          //LCD清屏
            key = 1;            //K1 按下 第二页
            break;
          case 3: 
            OLED_CLS();          //LCD清屏
            key = 2;            //K1 按下 第二页
            break;
          default:
            
            break;
        }
        
        if(0 == key)
        {
            OLED_P8x16Str(4,0,(uint8_t*)"LQ ADC Test Bat"); 
            
            printf("\r\n/AD0***********************%5d mv\r\n ",batv0);
            sprintf(txt,"AD0:%5d mv ",batv0);
            OLED_P8x16Str(20,2,(uint8_t*)txt);
            
            printf("\r\n/AD1***********************%5d mv\r\n ",batv1);
            sprintf(txt,"AD1:%5d mv ",batv1);
            OLED_P8x16Str(20,4,(uint8_t*)txt);
            
            printf("\r\n/AD2***********************%5d mv\r\n ",batv2);
            sprintf(txt,"AD2:%5d mv ",batv2);
            OLED_P8x16Str(20,6,(uint8_t*)txt);
            
        }
        if(1 == key)
        {
            printf("\r\n/AD3***********************%5d mv\r\n ",batv3);
            sprintf(txt,"AD3:%5d mv ",batv3);
            OLED_P8x16Str(20,0,(uint8_t*)txt);
            
            printf("\r\n/AD4***********************%5d mv\r\n ",batv4);
            sprintf(txt,"AD4:%5d mv ",batv4);
            OLED_P8x16Str(20,2,(uint8_t*)txt);
            
            printf("\r\n/AD5***********************%5d mv\r\n ",batv5);
            sprintf(txt,"AD5:%5d mv ",batv5);
            OLED_P8x16Str(20,4,(uint8_t*)txt);
            
            printf("\r\n/AD6***********************%5d mv\r\n ",batv6);
            sprintf(txt,"AD6:%5d mv ",batv6);
            OLED_P8x16Str(20,6,(uint8_t*)txt);    
        }
        if(2 == key)
        {
            printf("\r\n/AD7***********************%5d mv\r\n ",batv7);
            sprintf(txt,"AD7:%5d mv ",batv7);
            OLED_P8x16Str(20,0,(uint8_t*)txt);
            
            printf("\r\n/AD8***********************%5d mv\r\n ",batv8);
            sprintf(txt,"AD8:%5d mv ",batv8);
            OLED_P8x16Str(20,2,(uint8_t*)txt);
               
        }
   
        LED_Reverse(1);    
        delayms(100);
    }
    
}
#else
void Test_ADC(void)
{
    LED_Init();
    UART_Init(UART4, 115200);
    
    ADC_Init(ADC0);
    ADC_Init(ADC1);
    
    TFTSPI_Init(1);                 //LCD初始化  0:横屏  1：竖屏
    TFTSPI_CLS(u16BLUE);
    printf("ADC 测试例程");

    printf("ADC1_SE13 =13,       // PTB7      母板上的AD3\n ");
    printf("ADC1_SE14 =14,       // PTB10     母板上的AD4\n ");
  

    TFTSPI_P8X16Str(2,0,"LQ ADC Test",u16RED,u16BLUE);
   
    uint16_t batv3 = (uint16_t)(ADC_Get(3)*0.806);
    uint16_t batv4 = (uint16_t)(ADC_Get(4)*0.806);
   

    char txt[16];
    while(1)
    {
        /* 获取 ADC通道值 */
        batv3 = (uint16_t)(ADC_Get(3)*0.806);
        batv4 = (uint16_t)(ADC_Get(4)*0.806);
       
          
        
            TFTSPI_P8X16Str(4,0,(char*)"LQ ADC Test Bat",u16RED,u16BLUE); 
            
           
            printf("\r\n/AD3***********************%5d mv\r\n ",batv3);
            sprintf(txt,"AD3:%5d mv ",batv3);
            TFTSPI_P8X8Str(1,6,txt,u16RED,u16BLUE);
            
            printf("\r\n/AD4***********************%5d mv\r\n ",batv4);
            sprintf(txt,"AD4:%5d mv ",batv4);
            TFTSPI_P8X8Str(1,7,txt,u16RED,u16BLUE);
            
              
   
        LED_Reverse(1);    
        delayms(100);
    }
    
}
#endif
/* ===================================================================
**   电感AD采集归一化计算
** ===================================================================*/ 
float  AD_M_Right,AD_M_Left;
float Ad_Value(void)
{  
   int i;
   float  Left_Sum=0,Right_Sum=0;
   float  RightAverage,LeftAverage;
   float  LeftADC[20],RightADC[20]; //左电感采集，右电感采集
   int M_Left_max=4096;     //采集最大值      这里需要根据自己运放输出的最大值设置
   int M_Left_min=0;      //采集最小值
   int M_Right_max=4096;    //采集最大值      这里需要根据自己运放输出的最大值设置
   int M_Right_min=0;     //采集最小值
   
   for(i=0;i<20;i++)
    {   
        LeftADC[i]=ADC_Get(0);   //PTB4
        Left_Sum+=LeftADC[i];
        RightADC[i]=ADC_Get(1);   //PTB5
        Right_Sum+=RightADC[i];
    }

    RightAverage=Right_Sum/20;                  //计算20次的平均值
    LeftAverage=Left_Sum/20;
   
 AD_M_Left=100*(LeftAverage-M_Left_min)/(M_Left_max-M_Left_min);                //归一化到0-100
 AD_M_Right=100*(RightAverage-M_Right_min)/(M_Right_max-M_Right_min);           //归一化到0-100
return (AD_M_Left-AD_M_Right);
}