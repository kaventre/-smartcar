#ifndef __LQ_SD5_H
#define __LQ_SD5_H

/*------------------------------------------------------------------------------------------------------
【函    数】Test_SD5
【功    能】测试CMT输出PWM控制SD5舵机
【参    数】无
【返 回 值】无
【实    例】Test_SD5(); //测试SD5舵机
【注意事项】注意，一定要对舵机打角进行限制
--------------------------------------------------------------------------------------------------------*/
void Test_SD5(void);

/*------------------------------------------------------------------------------------------------------
【函    数】Test_FTMSD5
【功    能】测试FTM输出PWM控制SD5舵机
【参    数】无
【返 回 值】无
【实    例】Test_FTMSD5(); //测试SD5舵机
【注意事项】注意，一定要对舵机打角进行限制
--------------------------------------------------------------------------------------------------------*/
void Test_FTMSD5(void);
void Z_Test_FTMSD5(void);
void M_Test_FTMSD5(void);
void Y_Test_FTMSD5(void);
void mduoji_FTMSD5(double x);
void m1duoji_FTMSD5(double x);
void duoji_FTMSD5(double x);
#endif