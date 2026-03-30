# Datasets 101
When a model is trained on a daset it must learn these two things:
```
1. WHAT DOES EACH CLASS LOOK LIKE? The feature values that correspond with each class.
2. WHAT IS THE DISTRIBUTION OF CLASSES? How common each class is.
```

# IDS Datasets
1. It is normal for an IDS dataset to be 80% normal traffic and other 20% being attack traffic as long as within the 20% attack traffic each attack type is evenly distributed. 


# Techniques for Dataset Balancing 
### Dealing with both Classes - Adjusting Class Weights to Address Imbalance
Assigning weights to minority class forces the model to pay more attention to the patterns of that class, which increases the model understanding of it and forces it into performing better.
##### Use built-in tools
- **Simple**
Most ML frameworks have a built-in parameter "class weight" that can be adjusted and used to offest the imbalance.
2. In sklearn it can be set to *balanced*:
```
Balanced is defined by this formula:

n_sample / (n_classes * np.bincount(y))

n_samples = total rows in a dataset
n_classes = number of classes in dataset
np.bincount(y) = total count of a specific class in dataset.
```

code with using built-in
```
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_classification
import numpy as np
import pandas as pd
from sklearn.metrics import f1_score, accuracy_score, confusion_matrix


X, y = make_classification(n_samples=100000, n_features=2, n_informative=2,
                           n_redundant=0, n_repeated=0, n_classes=2,
                           n_clusters_per_class=1,
                           weights=[0.995, 0.005],
                           class_sep=0.5, random_state=42)
# Convert the data from numpy array to a pandas dataframe
df = pd.DataFrame({'feature1': X[:, 0], 'feature2': X[:, 1], 'target': y})
print(round(df.target.value_counts(normalize = True)*100),1)

X = df.drop(columns = 'target')
y = df['target']

X_train,X_test,y_train,y_test = train_test_split(X,
   y,test_size=0.2,random_state=42)
print(X_train.shape,y_train.shape)


model_1 = LogisticRegression(class_weight = 'balanced')
model_1.fit(X_train,y_train)
print(f'Accuracy score on balanced weights: {model_1.score(X_test,y_test)*100:.1f}%')
print(f'F1 score on balanced weights: {f1_score(y_test,model_1.predict(X_test)):.3f}')
conf_matrix_1=confusion_matrix(y_test,model_1.predict(X_test))
print(conf_matrix_1)
```

##### custom definition (this is better)
Use a custom/manual method to adjust weights if previous step is lowkey not working. The code below does this: 
1. generates a dataset with 2 classes
2. converts the dataset into data frame
3. split data for training and test
4. use custom function to adjust weights

```
def class_weight(labels_dict,mu=0.15):
    total = sum(labels_dict.values())
    keys = labels_dict.keys()
    weights = dict()
    for i in keys:
        score = np.log((mu*total)/float(labels_dict[i]))
        weights[i] = score if score > 1 else 1
    return weights

labels_dict = y.value_counts().to_dict()
weights = class_weight(labels_dict)

print('labels dictionary: ', labels_dict)
print('weights: ',weights)


model = LogisticRegression(class_weight = weights)
model.fit(X_train,y_train)
print(f'model_score for manual weights,{model.score(X_test,y_test)*100:.1f}%')
print(f'F1_score for manual weights {f1_score(y_test,model.predict(X_test)):.2f}')
conf_matrix = confusion_matrix(y_test,model.predict(X_test))
print(conf_matrix)
```

##### Performance
Note that in the example that showcased this code the manual method provided an f1_score that was more than 6x better than manual.


### Dealing with Minority Class - SMOTE (Synthetic Minority Oversampling Technique)
SMOTE creates new datsamples of minority class by creating new data points between any 2 samples of minority class. It does this by:
1. Start with some reference sample. 
2. Finds the k-neareast elemtns in terms of features among the same minority class.
3. Randomly selects a sample from the k elements, and interpolates it with the original sample. Creating a sample in between the two.
4. Repeat for a specified amount of times (until dataset is balanced).

NOTE: **"SMOTE is useful, but it’s probably not your first line of action when working with imbalanced datasets."**

**Pros**:
1. improves performance on minority class 
2. avoids overfitting by creating new samples instead of duplicating original ones.
3. works with weak classifiers (RF, logistic regression, SVM) for imbalanced datasets.


**Cons**:
1. if the dimension between exisitng samples of minority class is complex then interpolating them might not lead to meaningful results.
2. if classes are too similiar/boundary is not clearly defined it might create samples that are of non-intended class.

##### How to do it in Python?
```
https://www.kaggle.com/code/daniilnahliuk1/effects-of-applying-smote/edit
```

**NOTE**: [This study shows that using RandomOverSampler from imblearn produces better results than SMOTE](https://www.kaggle.com/code/marawaneslam/comparative-analysis-of-sampling-techniques/notebook)

### Dealing with Majority Class - Downsampling and Upweighting Majority Class
1. Downsampling the majority class.
2. Upweighting (loss on majority class) to minimize the prediction bias created from previous step.

This approach bring these benefits:
1. faster convergence during training because the model sees minority classes more often.
2. The model knows both true distribution of the classes and learns what feature values correspond with each class. 




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
