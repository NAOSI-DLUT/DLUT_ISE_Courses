# -*- coding: utf-8 -*-
"""
Created on 2019-05-27

@author: tony
"""

import matplotlib.pyplot as plt

# 设置中文字体
plt.rcParams['font.family'] = ['SimHei']

x = [5, 4, 2, 1]  # x轴坐标数据
y = [7, 8, 9, 10]  # y轴坐标数据

# 绘制线段
plt.plot(x, y, 'b', label='线1', linewidth=2)

plt.title('绘制折线图')  # 添加图表标题

plt.ylabel('y轴')  # 添加y轴标题
plt.xlabel('x轴')  # 添加x轴标题

plt.legend()  # 设置图例

# 以分辨率 72 来保存图片
plt.savefig('折线图', dpi=72)

plt.show()  # 显示图形