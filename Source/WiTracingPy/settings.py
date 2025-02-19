NETWORK_CONFIG = {
    "max_buffer_size": 65507,
    # "server_endpoint": ("192.168.31.110", 8888),
    "client_endpoint": ("192.168.31.110", 8888),
}

APP_CONFIG = {
    "preprocessed_csv_file": "data/preprocessed_data.csv",
    "historical_csv_file": "data/data.csv",
    "checkpoint_path": "checkpoints/deepAR",
    'training_history': "checkpoints/deepAR/history.csv",
    "training_epochs": 1,
    "data_size": 10000,
}

UNREAL_CONFIG = {
    # 'num_of_beacons': 22
    'rssi_max': 0,
    'rssi_min': -99,
}