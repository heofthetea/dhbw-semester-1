> Scales Feature values to a [[Standard-Normalverteilung]]


- Does this for _all_ features at once

```python
# 2. Scale the features
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)
```