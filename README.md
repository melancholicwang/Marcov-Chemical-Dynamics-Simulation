# Marcov-Chemical-Dynamics-Simulation #

使用马尔可夫链预测原子的运动轨迹或动量
根据马尔可夫C-K方程，以历史位置/动量预测下一步的原子位置/动量。
调用的主函数为marcovp(Source, num, LearnOrNotFlag, RecallOrNotFlag, GlobVariable)。


## 函数主体调用

1.	marcovp(Source, 20, 0, 0, GlobVariable)
//学习20步数据

2.	marcovp(Source, 20, 1, 0, GlobVariable)
//预测第21步，得到两组预测的数据

3.	marcovp(Source, 20, 1, 1, GlobVariable)
//如果第一次返回的数据超出容错范围，启用回溯机制

4.	marcovp(Source, 21, 0, 0, GlobVariable)
//如果回溯的结果仍然不准确，第21步将继续学习一步数据

5.	marcovp(Source, 21, 1, 0, GlobVariable)
//如果返回的预测数据在容错范围内，将此结果加入数据源中

6.	marcovp(Source, 21, 1, 0, GlobVariable)
//继续预测第22步数据

