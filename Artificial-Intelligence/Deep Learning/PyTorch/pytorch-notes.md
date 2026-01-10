# What is PyTorch?
Open Source Deep Learning Framework. Its integrated with Python.

## What\How\Why are Tensors withing PyTorch?
- specialized data structures (like arrays/matrices) that are used to encode parameters, inputs and outputs of a model.

# Neural Networks in PyTorch?
When working with NNs in PyTorch NNs are a collection of nested functions that are executed on some input data. These functions are defined by:
- parameters (weights and biases).

**torch.autograd** is Pytorch's differentiaion engine that powers neural network training.

Training of NNs happens in this way:
1. **Forward propagation**: NN makes its best guess about the correct output to achieve this it runs the input data through each of its function (neurons) aka making a guess.
2. **Backward propagation**: NN adjusts its parameters proportionate to the error in its guess. *How does it do it?* It does it by traversing the NN backwards from the output layer, collecting the derivatives of the error in respect to the parameters functions (gradients) and optimizing using **gradient descent**.

# How to make a NN in PyTorch?
### 1. Define a NN that has some learnable parameters or weights
Define the NN with its layers. Then define forward function and the backward function is automatically defined. 
Note: you can showcase learnable parameters by, 
```
#shows learnable parameters
params = list(nn_ex.parameters()) 
print(len(params))
print(params[0].size()) #conv1's weights
```

#### Layers?
- **Convolution Layers**: good at finding features (eyes, wheels, edges). 
- **Linear Layers**: good at logic. Takes features found by convolution layers and pieces them together to determine if object A and obect B make up object C. 
### 2. Iterate over a dataset of inputs
### 3. Process input through the netwrok
### 4. Compute the loss (how far the output is from being correct)
There is a loss function which takes the (output, target) pair of inputs, and computes a value that estimates how far away the output is from the target. 
**There are multiple types of loss functions** all are within nn package:
1.  nn.MSELoss -> computes mean-squared error between the outputs and the target.
2. 
3. 

### 5. Propagate gradients back into the network's parameters
### 6. Update the weights of the network, typically using a simple update rule
Simple update rule: ```weight = weight - learning_rate * gradient```
### 7. Rinse and repeat step 3-6 for N amount of times.



# Vocab
- **torch.Tensor**: A multi-dimensional array with support for autograd operations like backward(). Also holds the gradient w.r.t. the tensor.
- **nn.Module**: Neural network module. Convenient way of encapsulating parameters, with helpers for moving them to GPU, exporting, loading, etc.
- **nn.Parameters**: A kind of Tensor, that is automatically registered as a parameter when assigned as an attribute to a Module.
- **autograd.Parameter**: Implements forward and backward definitions of an autograd operation. Every Tensor operation creates at least a single Function node that connects to functions that created a Tensor and encodes its history.
- ****: