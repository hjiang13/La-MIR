import pandas as pd
import networkx as nx
import os

# 设置文件路径和结果CSV文件名
csv_file = './CFG_completion_analysis_results_GPT35.csv'  # 结果CSV文件路径
dot_file_base_path = '/home/anonymous/LLMs-in-IR/processed_data/Human_x_164_O3/organized dot/'  # DOT文件所在的目录
output_csv = 'summary_overall_completed_gpt35_summary.csv'  # 保存结果的CSV文件名

# 读取GPT3.5结果文件
df = pd.read_csv(csv_file)

# 筛选Overall Completed的CPP文件
completed_df = df[df['category'] == 'Overall Completed']

# 定义一个函数来计算图属性
def calculate_graph_properties(dot_file):
    try:
        # 读取DOT文件并创建图
        G = nx.drawing.nx_pydot.read_dot(dot_file)
        
        # 检查是否为多重图，如果是，将其转换为普通图
        if isinstance(G, nx.MultiGraph) or isinstance(G, nx.MultiDiGraph):
            G = nx.Graph(G)

        nodes = G.number_of_nodes()
        edges = G.number_of_edges()
        density = nx.density(G)
        avg_clustering = nx.average_clustering(G)  # 计算平均聚类系数
        degree_centrality = max(nx.degree_centrality(G).values())  # 最大度中心性
        connected_components = nx.number_connected_components(G)  # 连通分量数量

        return nodes, edges, density, avg_clustering, degree_centrality, connected_components

    except Exception as e:
        print(f"Error processing {dot_file}: {e}")
        return 0, 0, 0, 0, 0, 0

# 创建一个列表来存储结果
results = []

# 遍历所有的Completed文件
for index, row in completed_df.iterrows():
    cpp_file = row['file_name']
    dot_file = os.path.join(dot_file_base_path, cpp_file)
    
    if os.path.exists(dot_file):
        # 计算图属性
        nodes, edges, density, avg_clustering, degree_centrality, connected_components = calculate_graph_properties(dot_file)
        
        # 将结果添加到列表中
        results.append([
            cpp_file, nodes, edges, density, avg_clustering, degree_centrality, connected_components
        ])
    else:
        print(f"File not found: {dot_file}")

# 将结果保存为CSV文件
columns = [
    'file_name', 'nodes', 'edges', 'density', 'avg_clustering',
    'degree_centrality', 'connected_components'
]

results_df = pd.DataFrame(results, columns=columns)
results_df.to_csv(output_csv, index=False)

print(f"Graph properties saved to {output_csv}")
