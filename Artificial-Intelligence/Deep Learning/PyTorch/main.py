import torch
from torchvision.models import resnet18, ResNet18_Weights
import numpy as np


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

def main():
    print("PyTorch version:", torch.__version__)  
    autograd()

if __name__ == "__main__":
    main()