import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import gaussian_kde
from matplotlib.lines import Line2D

# 设置全局字体
plt.rcParams['font.size'] = 12  # 字体大小
plt.rcParams['font.family'] = 'Times New Roman'  # 字体样式

# 定义颜色和形状，确保不重复使用标记
styles = {
    'GPT4o Only': {'color': '#74AA9C', 'marker': 'o'},  # GPT4o Green, Circle
    'Gemma Only': {'color': '#EA4335', 'marker': 's'},  # Gemma Red, Square
    'MetaLlama Only': {'color': '#0081FB', 'marker': 'D'},  # Meta Llama Blue, Diamond
    'GPT4o and Gemma': {'color': '#FFA500', 'marker': '^'},  # GPT35 Orange, Triangle
    'GPT4o and MetaLlama': {'color': '#64B0D3', 'marker': 'v'},  # GPT4o and MetaLlama, Downward Triangle
    'MetaLlama and Gemma': {'color': '#95A7E4', 'marker': 'p'},  # MetaLlama and Gemma, Pentagon
    'All Three': {'color': '#89C0B9', 'marker': 'h'}  # Intersection of All, Hexagon
}

# 定义文件名和对应的标签
csv_files = {
    'summary_overall_completed_GPT4o_only_summary.csv': 'GPT4o Only',
    'summary_overall_completed_Gemma27b_only_summary.csv': 'Gemma Only',
    'summary_overall_completed_MetaLlama_only_summary.csv': 'MetaLlama Only',
    'summary_overall_completed_GPT4o_and_Gemma27b_summary.csv': 'GPT4o and Gemma',
    'summary_overall_completed_GPT4o_and_MetaLlama_summary.csv': 'GPT4o and MetaLlama',
    'summary_overall_completed_MetaLlama_and_Gemma27b_summary.csv': 'MetaLlama and Gemma',
    'summary_overall_completed_all_three_summary.csv': 'All Three'
}

# 读取每个CSV文件并提取Density数据
density_data = {}
for csv_file, label in csv_files.items():
    df = pd.read_csv(csv_file)
    density_data[label] = df['density'].dropna()  # 去除NaN值

# 设置Density区间和柱状图的bin
bins = np.arange(0, 0.3, 0.01)  # x轴范围增大至0.3

# 创建一个子图来绘制所有section的分布
fig, ax1 = plt.subplots(figsize=(12, 8))

# 绘制每个部分的柱状图，表示CPPfile的数量
for label, density in density_data.items():
    if len(density) > 1:  # 确保数据集中有多个元素
        ax1.hist(density, bins=bins, color=styles[label]['color'], alpha=0.5, label=label)

ax1.set_xlabel('Density')
ax1.set_ylabel('Number of CPP files')
ax1.set_ylim(0, 15)  # 根据实际数据情况调整y轴范围

# 创建第二个y轴用于绘制拟合曲线
ax2 = ax1.twinx()

# 计算每个部分的拟合曲线并绘制
for label, density in density_data.items():
    if len(density) > 1:  # 确保数据集中有多个元素
        kde = gaussian_kde(density, bw_method=0.4)  # 减小带宽以增加曲线高度
        x = np.linspace(0, 0.3, 500)
        y = kde(x)
        ax2.plot(x, y, color=styles[label]['color'], linestyle='-', linewidth=2,
                 marker=styles[label]['marker'], markevery=25, label=label)

ax2.set_ylabel('Possibility')

# 创建带有标记的图例
legend_elements = [Line2D([0], [0], color=styles[label]['color'], marker=styles[label]['marker'],
                          label=label, markersize=10, linestyle='-') for label in styles]
ax2.legend(handles=legend_elements, loc='best')

# 保存图表
plt.title('Distribution of Density for Each Section')
plt.savefig('density_distribution_with_dual_axes_and_font.png')

# 显示图表
plt.show()
