import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from scipy.stats import ttest_ind

# Load summary CSV files generated from the previous analysis
summary_wrong = pd.read_csv('summary_wrong_all_three_summary.csv')
summary_overall = pd.read_csv('summary_overall_completed_all_three_summary.csv')
summary_loop = pd.read_csv('summary_loop_completed_all_three_summary.csv')

# Add a column to identify the category
summary_wrong['category'] = 'Wrong'
summary_overall['category'] = 'Overall Completed'
summary_loop['category'] = 'Loop Completed'

# Combine all summaries into a single DataFrame
combined_summary = pd.concat([summary_wrong, summary_overall, summary_loop])

# Calculate summary statistics
summary_stats = combined_summary.groupby('category').agg(['mean', 'median', 'std', 'min', 'max'])
print(summary_stats)

# Visualize the data
metrics = ['nodes', 'edges', 'density', 'avg_clustering', 'degree_centrality', 'connected_components']

# Boxplot for each metric
for metric in metrics:
    plt.figure(figsize=(8, 6))
    sns.boxplot(x='category', y=metric, data=combined_summary)
    plt.title(f'Comparison of {metric.capitalize()} across Categories')
    plt.savefig(f'{metric}_boxplot.png')
    plt.show()

# Statistical Testing: Pairwise t-tests between categories for each metric
def pairwise_ttests(combined_summary, metric):
    categories = combined_summary['category'].unique()
    results = {}
    for i, cat1 in enumerate(categories):
        for cat2 in categories[i+1:]:
            data1 = combined_summary[combined_summary['category'] == cat1][metric]
            data2 = combined_summary[combined_summary['category'] == cat2][metric]
            t_stat, p_val = ttest_ind(data1, data2)
            results[f'{cat1} vs {cat2}'] = {'t-statistic': t_stat, 'p-value': p_val}
    return pd.DataFrame(results)

# Perform pairwise t-tests for each metric
for metric in metrics:
    ttest_results = pairwise_ttests(combined_summary, metric)
    print(f'Pairwise t-tests for {metric.capitalize()}')
    print(ttest_results)

# Example interpretation: Identify features with significant differences
for metric in metrics:
    ttest_results = pairwise_ttests(combined_summary, metric)
    significant_differences = ttest_results[ttest_results['p-value'] < 0.05]
    print(f'Significant differences for {metric.capitalize()}:')
    print(significant_differences)
