# What is Machine Learning?
Machine learning is a subfield of artificial intelligence that revolves around developing algortithms and programs that can learn over time, specifically learning from data.

**There are categories of ML**
1. **Supervised learning**: 
    - Model is trained on labeled data and based on that makes inferences.
    - Types: classification and regression.
    - Made up of these algortithms:
        - *Regression algorithms*—predict output values by identifying linear relationships between real or continuous values.
        - *Classification algorithms*—predict categorical output variables (e.g., “junk” or “not junk”) by labeling pieces of input data. 
        - *Neural networks*—simulate the way the human brain works, with a huge number of linked processing nodes that can facilitate processes like natural language translation, image recognition, speech recognition and image creation.
2. **Unsupervised learning**: 
    - Model is not trained on any data. Model draws inferences from identifying patterns in provided data.
    - Uses cluster analysis, which uses clustering algorithms to categorize data points according to value similarity (as in customer segmentation or anomaly detection).
3. **Self-supervised machine learning**:
    - Model trains itself on unlabeled data and through that creates its own labeled datasets.
4. **Reinforcement learning**: 
    - Model is trained using a system of reward and punishment. An agent is given a task to reach a pre-determined goal and a human punishes and rewards it based on what it does. Through time it learns the best way to reach that goal.
5. **Semi-supervised learning**:
    - Model is given a small labeled data set and a big unlabeled data set then the model uses a mix of unsupervised learning to identify data clusters, afterwards uses supervised learning to label those data clusters.

## What are phases (pipeline) of ML model?
 1. ***Problem Definition & Data Gathering***: Defining the objective and *Key Performance Indicators* which will allow to determine how effective the model is at its objective. The collecting data.
 2. ***Data Preprocessing & Preparation***: Cleaning up data, correct errors, format it and transform into usable state.
 3. ***Model Selection***: Choosing a proper model based on the objective.
 4. ***Model Training***: Training the model on collected data. Data from step 2 is split into 2: training(80%) and testing(20%).
 5. ***Model Evaluation***: After model is trained its evaluated against the testing data set.
 6. ***Hyperparameter Tuning***: Based on results from previous step go back and fine tune the model. **Iterative cycle of  tuning, training, and evaluating**.
 7. ***Deployment & Monitoring***: Deploy the model into real world environment and monitor how well it performs.

Collect data -> data -> preprocessing -> feature extraction -> features -> training model

## What are limitations of Machine Learning?
1. **Computing power requirements** add fuel into the fire that is climate change.
2. **Data** required for machine learning raises privacy concerns over sensitive data.
3. **Type of data** used for machine learning can perpetuate stereotypes/misinformed points. For example, a group of people from region A have less education due to a war thus they score less on SAT, machine learning doesn't know that context and will just show that based on data people in region A score less which could perpetuate a sterotype that people from that region are less intelligent.



# How to use machine learning?
# Vocab
**Inference** - prediction aka when a pre-trained model makes a prediction on an unseen data in the wild.
**Prediction serving** - process of client asks for inference -> supply new data -> server responds with result. 
**Feature** - an individual measurable property or characteristic of a phenomenon being observed.
**parameters** - *ATUOMATICALLY* - any of the variables and coefficients inside the actual mathematical model itself. These are the numbers used to make predictions when fed features as inputs and they are almost always determined automatically during the training process.
**hyper parameters** - *MANUALLY* - any configuration that is outside of the model and whose value cannot be estimated or tuned by the data. Vonfiguration values that we must set manually such as the size and shape of the model, the learning rate and number of training steps to take, which features to use and the methods and calculations to pre-process the data.