# VelocityLimitFilter & AccelerationLimitFilter

速度制限フィルタと加速度制限フィルタを使って入力信号の変化を制限した信号を生成します

{{ include_example("example/filter/vel_limit_filter.cpp") }}

## 速度制限フィルタ(VelocityLimitFilter)
入力の1回微分を制限します

![title](../fig/vel_limit.png)

## 加速度制限フィルタ(AccelerationLimitFilter)
入力の2回微分を制限します

![title](../fig/acc_limit.png)