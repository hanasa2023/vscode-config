import os

os.makedirs(os.path.join('..', 'data'), exist_ok=True)
data_file = os.path.join('..', 'data', 'house_tiny.csv')
with open(data_file, 'w') as f:
    f.write('NumRooms,Alley,Price\n')
    f.write('NA,1,127500\n')
    f.write('2,NA,178100\n')

import pandas as pd

data = pd.read_csv(data_file)
print(data, type(data))

inputs, outputs = data.iloc[:, 0:2], data.iloc[:, 2]
inputs = inputs.fillna(inputs.mean())
inputs = pd.get_dummies(inputs, dummy_na=True)
print(inputs)

import torch

X, Y = torch.tensor(inputs.values()), torch.tensor(outputs.values())
print(X, Y)