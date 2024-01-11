import torch

A = torch.arange(20, dtype=torch.float32).reshape(5, 4)
print(A)

B = torch.arange(30, dtype=torch.float32).reshape(2, 3, 5)
print(torch.norm(A), torch.norm(B))