import torch
import random
from d2l import torch as d2l

true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = d2l.synthetic_data(true_w, true_b, 1000)

# def data_iter(batch_size, features, labels):
#     num_examples = len(features)
#     indices = list(range(num_examples))
#     random.shuffle(indices)
#     for i in range(0, num_examples, batch_size):
#         batch_indices = torch.tensor(indices[i : min(i + batch_size, num_examples)])
#         yield features[batch_indices], labels[batch_indices]
data_iter = d2l.load_array

w = torch.normal(0, 0.01, [2, 1], requires_grad=True)
# w = torch.zeros([2, 1], requires_grad=True)
b = torch.zeros(1, requires_grad=True)
lr = 0.03
num_epochs = 3
net = d2l.linreg
loss = d2l.squared_loss
batch_size = 10

for i in range(num_epochs):
    for X, y in data_iter((features, labels), batch_size):
        l = loss(net(X, w, b), y)
        l.sum().backward()
        d2l.sgd([w, b], lr, batch_size)
    with torch.no_grad():
        train_l = loss(net(X, w, b), y)
        print(f'epoch = {i}, loss {float(train_l.mean())}\n')