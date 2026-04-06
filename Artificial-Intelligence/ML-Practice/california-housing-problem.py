# Exercise: The "Noise Injection" Test
# The goal is to determine if your model is actually learning patterns or simply memorizing noise.
from sklearn.datasets import fetch_california_housing
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor as rfr

import pandas as pd
import numpy as np

data = fetch_california_housing(as_frame=True)
X = pd.DataFrame(data.data, columns=data.feature_names)
y = data.target

X['Random Noise'] = np.random.normal(0, 1, len(X)) #random values (noise)

train_X, val_X, train_y, val_y = train_test_split(X, y, test_size=0.2, random_state=1)
max_depths = [1, 5, 10, 20, 50, 100]

depth_per_noise_improtance = []

temp_cols = data.feature_names
temp_cols.append('Noise')

for depth in max_depths:
    rf_model = rfr(max_depth=depth,random_state=1)
    rf_model.fit(train_X, train_y)

    important_per_col = []

    for importance, col_name in zip(rf_model.feature_importances_, temp_cols):
        important_per_col.append((col_name, float(importance)))
        if len(important_per_col) == 9: depth_per_noise_improtance.append((depth, float(importance)))

    print(important_per_col)


print("The depth of RF vs how important the noise becomes")
print(depth_per_noise_improtance)


### Conclusion is that as rf gains more budget it will try to learn patterns from the noise even thought it is irrelevant because statistically the random values in that column will sometimes (albeit rarely) lead to a correct prediction. 