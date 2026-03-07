# Datasets 101
When a model is trained on a daset it must learn these two things:
```
1. WHAT DOES EACH CLASS LOOK LIKE? The feature values that correspond with each class.
2. WHAT IS THE DISTRIBUTION OF CLASSES? How common each class is.
```

# Techniques for Dataset Balancing 
### Downsampling and Upweighting Majority Class
1. Downsampling the majority class.
2. Upweighting (loss on majority class) to minimize the prediction bias created from previous step.

This approach bring these benefits:
1. faster convergence during training because the model sees minority classes more often.
2. The model knows both true distribution of the classes and learns what feature values correspond with each class. 


# IDS Datasets
1. It is normal for an IDS dataset to be 80% normal traffic and other 20% being attack traffic as long as within the 20% attack traffic each attack type is evenly distributed. 






# Vocab
1. **majority class** - more common label/class in a dataset.
2. **minority class** - less common label/class in a dataset.
3. **Downsampling**:
    - lowering the percentage of majority class samples in the dataset, which makes the ratio of majority to minority much better for training an accurate model. 
    - Dataset is forced to become more balanced by throwing out many of the majority class samples from training. Increases the chances of more minority class samples being included in each training batch. 
    - Introduces a prediction bias by feeding/showing a model an aritifical world. 
4. **Upweighting**:
    - means treating the loss more harshly than it actually is. 
    - Used in training on datasets where majority class was downsampled to make for a more balanced dataset, to reflect the real world and minimize the prediction bias that is introduced by downsampling.
