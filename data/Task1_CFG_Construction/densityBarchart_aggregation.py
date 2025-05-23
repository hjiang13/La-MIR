import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import UnivariateSpline
from matplotlib.lines import Line2D

# 设置全局字体
plt.rcParams['font.size'] = 12  # 字体大小
plt.rcParams['font.family'] = 'Times New Roman'  # 字体样式

# 定义颜色和形状，确保不重复使用标记
styles = {
    'GPT4o': {'color': '#74AA9C', 'marker': 'o'},  # GPT4o Green, Circle
    'Gemma': {'color': '#EA4335', 'marker': 's'},  # Gemma Red, Square
    'MetaLlama': {'color': '#0081FB', 'marker': 'D'},  # Meta Llama Blue, Diamond
    'GPT35': {'color': '#FFA500', 'marker': '^'},  # GPT35 Orange, Triangle
}

# 定义文件名和对应的标签
csv_files = {
    'GPT4o': [
        'summary_overall_completed_GPT4o_only_summary.csv',
        'summary_overall_completed_GPT4o_and_Gemma27b_summary.csv',
        'summary_overall_completed_GPT4o_and_MetaLlama_summary.csv',
        'summary_overall_completed_all_three_summary.csv'
    ],
    'Gemma': [
        'summary_overall_completed_Gemma27b_only_summary.csv',
        'summary_overall_completed_GPT4o_and_Gemma27b_summary.csv',
        'summary_overall_completed_MetaLlama_and_Gemma27b_summary.csv',
        'summary_overall_completed_all_three_summary.csv'
    ],
    'MetaLlama': [
        'summary_overall_completed_MetaLlama_only_summary.csv',
        'summary_overall_completed_GPT4o_and_MetaLlama_summary.csv',
        'summary_overall_completed_MetaLlama_and_Gemma27b_summary.csv',
        'summary_overall_completed_all_three_summary.csv'
    ],
    'GPT35': [
        # 假设此模型是 GPT4o 的子集，可以添加其他相关文件
    ]
}

# 读取每个模型的所有部分并累加Density数据
density_data = {}
for model, file_list in csv_files.items():
    combined_density = []
    for csv_file in file_list:
        df = pd.read_csv(csv_file)
        combined_density.extend(df['density'].dropna().values)
    density_data[model] = np.array(combined_density)

# 设置Density区间和柱状图的bin
bins = np.arange(0, 0.3, 0.01)  # x轴范围增大至0.3
bin_centers = 0.5 * (bins[1:] + bins[:-1])

# 创建一个子图来绘制所有模型的分布
plt.figure(figsize=(12, 8))

# 绘制每个模型的柱状图，表示累加后的CPPfile的数量
for model, density in density_data.items():
    if len(density) > 1:  # 确保数据集中有多个元素
        counts, _, _ = plt.hist(density, bins=bins, color=styles[model]['color'], alpha=0.5, label=model)
        
        # 使用UnivariateSpline拟合柱状图的高度
        spline = UnivariateSpline(bin_centers, counts, s=0.5)
        x_smooth = np.linspace(bins[0], bins[-1], 1000)
        y_smooth = spline(x_smooth)
        plt.plot(x_smooth, y_smooth, color=styles[model]['color'], linestyle='-', linewidth=2,
                 marker=styles[model]['marker'], markevery=50, label=f"{model} Trend")

# 创建带有标记的图例
legend_elements = [Line2D([0], [0], color=styles[model]['color'], marker=styles[model]['marker'],
                          label=model, markersize=10, linestyle='-') for model in styles]

plt.legend(handles=legend_elements, loc='best')

# 调整y轴范围使曲线更高
plt.ylim(0, 20)  # 根据实际数据情况调整y轴范围

# 添加图例和标签
plt.xlabel('Density')
plt.ylabel('Number of CPP files')
plt.title('Aggregated Distribution of Density for Each Model with Trends')

# 保存图表
plt.savefig('density_distribution_with_trends.png')

# 显示图表
plt.show()
