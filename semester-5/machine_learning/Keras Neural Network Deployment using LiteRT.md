
- **Problem**: [[Keras]]/[[TensorFlow]] has a lot of python batching overhead, relies on [[GPU]]
	- => good for large, complex networks that can operate on _batches_ of data
	- but: bad for quick inference in low-resource environments
- **Solution**: [LiteRT](https://developers.google.com/edge/litert) (built by google), a low-level C++ API for model deployment

## 1. Convert Keras/TF model to LiteRT file representation
```python
import tensorflow as tf

# Convert the model
converter = tf.lite.TFLiteConverter.from_keras_model(model_2)
tflite_model = converter.convert()

# Save the model
with open(f"{MODEL_NAME}.tflite", 'wb') as f:
	f.write(tflite_model)
```


> [!hint] No additional libraries besides [[TensorFlow]] required

## 2. Dependency
```bash
uv add ai-edge-litert
```


## 3. Load & run model using the CompiledModel API
- very low-level:
	- requires writing to an input Buffer (directly in [[Memory]])
- [[Neural Network|Network]] reads directly from that buffer, and writes into a specified output buffer

> [!warning] You're doing [[C]] magic here, it's probably possible to segfault your python program if you're not careful

```python
input_vector = self.construct_input_vector(login_event)

input_buffers[0].write(input_vector)

self.model.run_by_index(0, input_buffers, output_buffers)

risk_score = output_buffers[0].read(1, np.float32)[0]
```

> [!hint] The indices (here 0) probably allow a parallelized run of the model on multiple inputs at the same time, which may be useful in a production situation.

# Weiterführend
- the docs: https://developers.google.com/edge/litert/next/python

> [!question] How much can I gain by using the C++ interface from [[Rust]] instead of python?


