import torch

A = torch.arange(20).reshape(5, 4)
print(A)
print(A/A.sum(axis=1))