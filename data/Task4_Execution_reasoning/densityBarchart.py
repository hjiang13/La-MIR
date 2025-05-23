import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import gaussian_kde

# 定义颜色
colors = {
    'Unique to GPT4o': '#74AA9C',  # GPT4o Green
    'Unique to Gemma': '#EA4335',  # Gemma Red
    'Unique to Meta Llama': '#0081FB',  # Meta Llama Blue
    'GPT4o and Gemma': '#FFB370',  # Intersection of GPT4o and Gemma
    'Gemma and Meta Llama': '#95A7E4',  # Intersection of Gemma and Meta_Llama
    'GPT4o and Meta Llama': '#64B0D3',  # Intersection of GPT4o and Meta_Llama
    'Intersection of All': '#89C0B9'   # Intersection of all three
}

# 读取每个section的csv文件并提取Density数据
density_data = {}
section_labels = {
    '100': 'Unique to GPT4o',
    '010': 'Unique to Gemma',
    '001': 'Unique to Meta Llama',
    '110': 'GPT4o and Gemma',
    '011': 'Gemma and Meta Llama',
    '101': 'GPT4o and Meta Llama',
    '111': 'Intersection of All'
}

for section_code, section_name in section_labels.items():
    df = pd.read_csv(f'./graph_properties_output/section_{section_code}.csv')
    density_data[section_name] = df['density']

# 设置Density区间和柱状图的bin
bins = np.arange(0, 0.16, 0.0025)

# 创建一个子图来绘制所有section的分布
plt.figure(figsize=(12, 8))

# 绘制每个section的柱状图
for section_name, density in density_data.items():
    plt.hist(density, bins=bins, color=colors[section_name], alpha=0.5, label=section_name, density=True)

# 计算每个section的拟合曲线并绘制
for section_name, density in density_data.items():
    kde = gaussian_kde(density,bw_method=0.5)
    x = np.linspace(0, 0.15, 1000)
    plt.plot(x, kde(x), color=colors[section_name], linestyle='-', linewidth=2)

# 添加图例和标签
plt.xlabel('Density')
plt.ylabel('Probability Density')
plt.title('Probability Distribution of Density for Each Section')
plt.legend()

# 保存图表
plt.savefig('density_distribution.png')

# 显示图表
plt.show()
