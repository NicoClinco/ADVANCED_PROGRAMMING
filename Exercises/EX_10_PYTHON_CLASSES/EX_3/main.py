from data_processor import *

def main():
    processor = DataProcessor(data,data_config);
    processor_2 = data_analysis.DataProcessor(data,data_config);
    final_result = processor.run_processing()
    print("Final processed data:")
    print(final_result)

if __name__ == "__main__":
    main()

