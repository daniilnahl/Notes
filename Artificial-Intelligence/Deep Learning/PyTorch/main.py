import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim

from torchvision.models import resnet18, ResNet18_Weights
import numpy as np

import pytorch_practice1 as pp1 

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        # 1 input image channel, 6 output channels, 5x5 square convolution
        #kernel
        self.conv1 = nn.Conv2d(1, 6, 5) #NN layer? 1 input to 6 outputs
        self.conv2 = nn.Conv2d(6, 16, 5) ##NN layer? 6 inputs to 16 outputs
        # an affine operation: y = Wx + b
        self.fc1 = nn.Linear(16 * 5 * 5, 120)  # 5*5 from image dimension
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)
    
    def forward(self, input):
        # Convolution layer C1: 1 input image channel, 6 output channels,
        # 5x5 square convolution, it uses RELU activation function, and
        # outputs a Tensor with size (N, 6, 28, 28), where N is the size of the batch
        c1 = F.relu(self.conv1(input))
        # Subsampling layer S2: 2x2 grid, purely functional,
        # this layer does not have any parameter, and outputs a (N, 6, 14, 14) Tensor
        s2 = F.max_pool2d(c1, (2, 2))
        # Convolution layer C3: 6 input channels, 16 output channels,
        # 5x5 square convolution, it uses RELU activation function, and
        # outputs a (N, 16, 10, 10) Tensor
        c3 = F.relu(self.conv2(s2))
        # Subsampling layer S4: 2x2 grid, purely functional,
        # this layer does not have any parameter, and outputs a (N, 16, 5, 5) Tensor
        s4 = F.max_pool2d(c3, 2)
        # Flatten operation: purely functional, outputs a (N, 400) Tensor
        s4 = torch.flatten(s4, 1)
        # Fully connected layer F5: (N, 400) Tensor input,
        # and outputs a (N, 120) Tensor, it uses RELU activation function
        f5 = F.relu(self.fc1(s4))
        # Fully connected layer F6: (N, 120) Tensor input,
        # and outputs a (N, 84) Tensor, it uses RELU activation function
        f6 = F.relu(self.fc2(f5))
        # Fully connected layer OUTPUT: (N, 84) Tensor input, and
        # outputs a (N, 10) Tensor
        output = self.fc3(f6)
        return output      
 

def tensors():
    #1. Tensor Initialization aka ways to create them
    print("Tensor Inits")
    #1.a directly from data, data type is auto. inferred
    data = [[1,2], [3,4]]
    x_data = torch.tensor(data)

    #1.b from NumPy arrays (also vice versa)
    np_arr = np.array(data)
    x_np = torch.from_numpy(np_arr)

    #1.c from another tensor
    x_ones = torch.ones_like(x_data) # retains the properties of x_data
    print(f"Ones Tensor: \n {x_ones}\n")

    x_rand = torch.rand_like(x_data, dtype=torch.float) # overrides the datatype of x_data
    print(f"random tnesor: \n {x_rand}")

    #1.d from random/constant values
    shape = (2,3,)
    rand_tensor = torch.rand(shape)
    ones_tensor = torch.ones(shape)
    zeros_tensor = torch.zeros(shape)

    print(f"Random tensor:\n{rand_tensor}\n")
    print(f"Ones tensor:\n{ones_tensor}\n")
    print(f"Zero tensor:\n{zeros_tensor}\n")    

    # 2. Tensor attributes - describe their shape, datatype, device on which they are stored
    print("\n\nTensor attributes\n\n")
    tensor = torch.rand(12,12)
    print(f"Shape of tensor {tensor.shape}")
    print(f"Datatype of tensor: {tensor.dtype}")
    print(f"Device tensor is stored on: {tensor.device}")


    # 3. Tensor Operations - over 100 tensor operations are present, but here I will only go over the main ones
    print("\n\nTensor operations\n\n")

    #3.a indexing and slicing
    tensor = torch.ones(4,4)
    tensor[:,1] = 0
    print(tensor)

    #3.b joining tensors (concatenating a sequence of tensors along a given dimension)
    t1 = torch.cat([tensor, tensor, tensor], dim=1)
    print(t1)

    #3.c multiplying tensors
    ## this does Aij * Bij
    print(f"tensor.mul(tensor)=\n {tensor.mul(tensor)}\nOR\ntensor * tensor=\n{tensor *tensor}\n")

    #3.d matrix multiplying tensors
    ## this does standard linear algebra matrix multiplication
    print(f"tensor.matmul(tensor.T)=\n{tensor.matmul(tensor.T)}\nOR\ntensor @ tensor.T=\n{tensor @ tensor.T}\n")

    #3.e in place operations using '_' suffix
    print(tensor, "\n")
    tensor.add_(5)
    print(tensor)
    ####note from course: in place operations save memory but can be problematic when doing derivatives because of an imediate loss of history

    # 4. Bridge with NumPy - tensors on CPU and numpy arrays can share their underlying memory locations
    # and changing one will the change the other
    print("\n\nBriding tensors with NumPy\n\n")

    # 4.a tensor to numpy array
    t = torch.rand(5)
    print(f"tensor=\n{t}\n")
    n = t.numpy()
    print(f"tensor converted into numpy array=\n{n}\n\n")

    #4.b change of tensor changes the numpy
    t.mul_(1.5)
    print(f"t: {t}")
    print(f"n: {n}\n")
    np.add(n, 1, out=n)
    print(f"t: {t}")
    print(f"n: {n}\n")
    
    #4.c numpy array to tensor
    n = np.ones(6)
    t = torch.from_numpy(n)
    print(f"t: {t}")
    print(f"n: {n}\n")

    #4.d change in numpy array changes the tensor
    np.add(n, 5, out=n)
    print(f"t: {t}")
    print(f"n: {n}")

def autograd():
    # What is autograd? It is a pytorch differentiation engine that powers neural network training.
    # loaded pretrained resnet18 model
    model = resnet18(weights=ResNet18_Weights.DEFAULT)
    # random tensor to represent an image with 3 channels and height&width of 64
    data = torch.rand(1, 3, 64, 64)
    labels = torch.rand(1,1000)

    #forward pass - running input data through the model and each of its layers to make a prediction
    prediction = model(data)

    #calcuate the error (loss)
    loss = (prediction - labels).sum()
    #backpropagate the error through the network, autograd calculates and stores the gradients for each model parameter in the parameter's .grad attribute
    loss.backward()
    #load optimizer, with learning rate of 0.01 and momentum (basically how much of previous 'direction' should be considered in this iteration, speeds up the process) 0.9
    optim = torch.optim.SGD(model.parameters(), lr=1e-2, momentum=0.9)
    #initiate gradient descent and optimizer adjusts each parameter by its gradient stored with '.grad'
    optim.step()

def nn_example():
    nn_ex = Net()
    
    ##EXAMPLE 1
    #shows learnable parameters
    params = list(nn_ex.parameters()) 
    print(len(params))
    print(params[0].size()) #conv1's weights


    ##EXAMPLE 2
    #random 32x32 input - process it
    input = torch.randn(1, 1, 32, 32)
    out = nn_ex(input)
    #print(out)

    #zero gradient buffers of all parameters and back prop. with random gradients
    nn_ex.zero_grad()
    out.backward(torch.randn(1, 10))
    #print(out)


    #ACTUAL PRACTICE
    #1 declare nn, feed it input, compute loss, backpropagate, update the weights, feed input again 
    ##declare nn
    nnn = Net()
    ##feed input
    input1 = torch.randn(1, 1, 32, 32)
    out1 = nnn(input1)

    target = torch.randn(10) # a dummy target, for example
    target = target.view(1, -1) # make it the same shape as output

    ##compute loss
    criterion = nn.MSELoss()
    loss = criterion(out1, target) #compare the two?
    print("The loss is\n")
    print(loss)

    ##graph of computitons in backward direction
    print(loss.grad_fn)  # MSELoss
    print(loss.grad_fn.next_functions[0][0])  # Linear
    print(loss.grad_fn.next_functions[0][0].next_functions[0][0])  # ReLU



    print('conv1.bias.grad before backward and before zeroing')
    print(nnn.conv1.bias.grad)
    ##back prop.
    nnn.zero_grad() # zeroes the gradient buffers of all parameters
    print('conv1.bias.grad before backward and after zeroing')
    print(nnn.conv1.bias.grad)

    loss.backward()
    print('conv1.bias.grad after backward')
    print(nnn.conv1.bias.grad)

    ##adjusting weights - 2 methods
    ### simplest update rule used in practice is the Stochastic Gradient Descent (SGD)  -> weight = weight - learning_rate * gradient. Don't do that use the sample code below (faster)
    learning_rate = 0.01
    for f in nnn.parameters():
        f.data.sub_(f.grad.data * learning_rate)

    ###method 2: using torch.optim that implements various methods of adjusting weight (using SGD,Nesterov-SGD, Adam, RMSProp, etc )
    # create your optimizer
    optimizer = optim.SGD(nnn.parameters(), lr=0.01)

    # in your training loop:
    optimizer.zero_grad()   # zero the gradient buffers
    output = nnn(input)
    loss = criterion(output, target)
    loss.backward()
    optimizer.step()    # Does the update

def main():

    print("PyTorch version:", torch.__version__)  
    pp1.main()

if __name__ == "__main__":
    main()