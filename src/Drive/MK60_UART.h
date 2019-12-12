/******************** LQ_K60_函数库 v1.0 ********************
 * 文件名           ：UART.H
 * 功能             ：设置UART工作模式
 * 备注             ：官方例程上修改
 * 日期             ：2015-10-16
 * 实验平台         ：龙丘 k60DN512Z核心板 
 * 作者             ：龙丘技术 006
 * 淘宝店           ：https://longqiu.taobao.com
 * 龙丘智能车讨论群 ：202949437
*************************************************************/

#ifndef __UART_H__
#define __UART_H__


/**********************************  UART(引脚复用) ***************************************/
//      模块通道    端口          可选范围                          建议
#define UART0_RX    PTA15       //PTA1、PTA15、PTB16、PTD6         PTA1不要用（与J-LINK冲突）
#define UART0_TX    PTA14        //PTA2、PTA14、PTB17、PTD7        PTA2不要用（与J-LINK冲突）

#define UART1_RX    PTC3        //PTC3、PTE1
#define UART1_TX    PTC4        //PTC4、PTE0

#define UART2_RX    PTD2        //PTD2
#define UART2_TX    PTD3        //PTD3

#define UART3_RX    PTC16       //PTB10、PTC16、PTE5
#define UART3_TX    PTC17       //PTB11、PTC17、PTE4

#define UART4_RX    PTE25       //PTC14、PTE25
#define UART4_TX    PTE24       //PTC15、PTE24


/**********************************  UART(引脚复用) ***************************************/




/*********************** UART功能函数 **************************/
//-------------------------------------------------------------------------*
//函数名: UART_Init                                                        
//功  能: 初始化UART                                                        
//参  数: uratn:模块名如：UART0 
//        baud: 波特率
//返  回: 无                                                              
//简  例: uart_init(UART4,115200);UART4对应引脚参考UART.H文件                                   
//-------------------------------------------------------------------------*
void UART_Init (UART_Type * uratn, uint32 baud);



//-------------------------------------------------------------------------*
//函数名: UART_PutChar                                                        
//功  能: 发送一个字节                                                       
//参  数: uratn:模块名如：UART0 
//         ch: 发送的字节
//返  回: 无                                                              
//简  例: UART_PutChar (UART4, 0x66);                               
//-------------------------------------------------------------------------*
void UART_PutChar(UART_Type * uratn, char ch);




//-------------------------------------------------------------------------*
//函数名: UART_PutBuff                                                        
//功  能: 发送指定len个字节长度数组 （包括 NULL 也会发送）                                                       
//参  数: uratn:模块名如：UART0 
//        buff: 发送的地址、
//        len : 发送指定长度
//返  回: 无                                                              
//简  例: UART_PutBuff (UART4, "123456789",5);实际发送5个字节‘1’‘2’‘3’‘4’‘5’                               
//-------------------------------------------------------------------------*
void UART_PutBuff(UART_Type * uratn, uint8_t *buff, uint32 len);



//-------------------------------------------------------------------------*
//函数名: UART_PutStr                                                        
//功  能: 发送字符串(遇 NULL 停止发送)                                                       
//参  数: uratn:模块名如：UART0 
//        str: 发送的地址、
//返  回: 无                                                              
//简  例: UART_PutStr (UART4, "123456789");实际发送9个字节                              
//-------------------------------------------------------------------------*
void UART_PutStr(UART_Type * uratn, char *str);



//-------------------------------------------------------------------------*
//函数名: UART_GetChar                                                        
//功  能: 发送字符串(遇 NULL 停止发送)                                                       
//参  数: uratn:模块名如：UART0 
//返  回: 串口收到的数据                                                               
//简  例: UART_GetChar (UART4); 获取串口收到的数据                              
//-------------------------------------------------------------------------*
char UART_GetChar(UART_Type * uratn);


uint8_t UART_GetNum(UART_Type * uartn);
/********************************************************************/

#endif 
