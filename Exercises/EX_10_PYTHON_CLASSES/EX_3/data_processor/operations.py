
import pandas as pd

# Configuration settings.
data_config = {
    'column1': 'A',
    'column2': 'B',
    'result_column': 'Result',
    'additional_column1': 'Additional1',
    'additional_column2': 'Additional2',
}

data = pd.DataFrame({
    data_config['column1']: [1, 2, 3, 4],
    data_config['column2']: [5, 6, 7, 8],
})

def process_data(df):
    df[data_config['result_column']] = df[data_config['column1']] + df[data_config['column2']]
    return df

def analyze_data(df):
    mean_val = df[data_config['result_column']].mean()
    max_val = df[data_config['result_column']].max()
    return mean_val, max_val

def additional_operation(df):
    df[data_config['additional_column1']] = df[data_config['column1']] * df[data_config['column2']]
    df[data_config['additional_column2']] = df[data_config['column1']] / df[data_config['column2']]
    return df
