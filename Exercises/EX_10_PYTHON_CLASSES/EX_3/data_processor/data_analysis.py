import pandas as pd

from .operations import *

class DataProcessor:
    def __init__(self, data, config):
        self.data = data
        self.config = config

    def run_processing(self):
        processed_data = process_data(self.data)
        result = analyze_data(processed_data)
        print(f"Mean: {result[0]}, Max: {result[1]}")
        additional_data = additional_operation(processed_data)
        return additional_data
