# Decision Tree?
A very basic model that based on some input goes into either of its 2 branches and produces a prediction (leaf). It looks like this:
```
  O input node
 / \
O   O predictions (2 leafs)
```


The above decision tree only has a depth of 0 (technically, because it makes a split and then goes straight into prediction).
**The amount of splits in a tree before arriving to a leaf determines the depth of a decision tree.** Also, remember that **amount of leafs is determined by 2^n where n is number of splits.**


# Random Forest?
A model that utilizes a lot of simple trees to get a list of predictions it then takes the average of those predictions and returns it as the main prediction. Main benefit is that this model often works very well without any tuning.
