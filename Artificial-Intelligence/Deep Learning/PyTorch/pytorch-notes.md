# What is PyTorch?
Open Source Deep Learning Framework. Its integrated with Python.

## What\How\Why are Tensors withing PyTorch?
- specialized data structures (like arrays/matrices) that are used to encode parameters, inputs and outputs of a model.

# Neural Networks in PyTorch?
When working with NNs in PyTorch NNs are a collection of nested functions that are executed on some input data. These functions are defined by:
- parameters (weights and biases).


Training of NNs happens in this way:
1. **Forward propagation**: NN makes its best guess about the correct output to achieve this it runs the input data through each of its function (neurons) aka making a guess.
2. **Backward propagation**: NN adjusts its parameters proportionate to the error in its guess. *How does it do it?* It does it by traversing the NN backwards from the output layer, collecting the derivatives of the error in respect to the parameters functions (gradients) and optimizing using **gradient descent**.