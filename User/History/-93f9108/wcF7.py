import torch
from torch import nn
from d2l import torch as d2l

# 生成数据集
true_w = torch.tensor([1, -3.2])
true_b = 4.2
features, labels = d2l.synthetic_data(true_w, true_b, 1000)

# 读取数据集
batch_size = 10
data_iter = d2l.load_array((features, labels), batch_size)

# 定义模型
net = nn.Sequential(nn.Linear(2, 1))
# 初始化模型参数
net[0].weight.data.normal_(0, 0.001)
net[0].bias.data.fill_(0)
# 定义损失函数
loss = nn.MSELoss()
# 定义优化算法
trainer = torch.optim.SGD(net.parameters(), lr=0.03)

# 开始训练
num_epochs = 3
for i in range(num_epochs):
    for X, y in data_iter:
        l = loss(net(X), y)
        trainer.zero_grad()
        l.backward()
        trainer.step()
    l = loss(net(features), labels)
    print(f'epoch is {i + 1}, loss = {l:f}')