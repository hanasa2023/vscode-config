import torch

A = torch.arange(20, dtype=torch.float32).reshape(5, 4)
print(A)

B = torch.arange(30, dtype=torch.float32).reshape(2, 3, 5)
print(torch.norm(A), torch.norm(B))

x = torch.arange(4.0, requires_grad=True)
print(x.grad)
y = 2 * torch.dot(x, x)
y.backward()
print(y, x.grad)