[[Linearregression]], [[Logarithmus]], [[List comprehension]], [[Gerade]]


- me learning Matplotlib lol
- also scipy's curve_fit is really neat


```python
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

# i've given them generic names now so it's hopefully a bit easier to understand what's going on
x_values = [i / 2 for i in range(11)]
y_values = [
    161.208,
    121.708,
    107.708,
    77.208,
    41.208,
    38.208,
    28.208,
    21.708,
    11.008,
    7.408,
    3.608,
]


## TODO: put logic here to compute CORRECT error values
# (any AI can generate this if you feed it a formula and the rest of the code)
#
# You can of course also just create this as a list of you rerror values for each point
# What I'm doing here currently is just taking a hardcoded template value (0.16742069)
# and duplicatiing it len(y_values) times to create a list of that length
yerrs = len(y_values) * [0.1_67_420_69]

# length correctness check, optional
assert len(x_values) == len(y_values) and len(yerrs) == len(y_values)


# Take the base 10 log of every measurement to artificially create a logarithmic scale
y_values = np.log10(y_values)


# template function for a polynomial of degree 1
def template_linreg(x, a, b):
    return a * x + b

# use measurement data to approximate a and b of the template function
# How to read this: curve_fit does a NUMERICAL approximation based on a least-squares error metric
# We feed it three arguments: 
#   1. a template function with n parameters, 
#   2. a list of x values and 
#   3. a list of y values corresponding to these x values
# curve_fit then does its magic and and returns the determined optimum (popt_linreg) for the 
# n parameters our template function takes as parameters in a list of length n
# Hope that made sense :]
(popt_linreg, _) = curve_fit(template_linreg, x_values, y_values)
# pretty output :P
print(f"Linear regression line: y = {round(popt_linreg[0], 3)}x + {round(popt_linreg[1], 3)} ")


## Approximate a and b for shallow and steep lines
# NOTE: We're feeding curve_fit only two points each - it is analytically possible to construct an exact
# line y = ax + b that perfectly fits two points - we do it numerically here but the results should be identical and it's far less cognitive effort
# However curve_fit will throw a fit over not being able to compute the covariance (measurement of how far off its estimates are) because the estimated 
# values are perfect, so don't freak out if you see those warnings

# first and last x coordinate we have
(x0, xn) = (x_values[0], x_values[-1])

(popt_steep, _) = curve_fit(template_linreg, [x0, xn], [y_values[0] - yerrs[0], y_values[-1] + yerrs[-1]])
(popt_shallow, _) = curve_fit(template_linreg, [x0, xn], [y_values[0] + yerrs[0], y_values[-1] - yerrs[-1]])
print(popt_steep, popt_shallow)


# convert our estimated polynomials into two lists that are plottable
x_linspace = np.linspace(0, x_values[-1])
y_popt = template_linreg(x_linspace, *popt_linreg)
y_shallow = template_linreg(x_linspace, *popt_shallow)
y_steep = template_linreg(x_linspace, *popt_steep)

# plot all our lines as lines over the linear space constructed from our x
plt.plot(x_linspace, y_popt, color="#000", label="Optimal fit", linestyle="-")
plt.plot(x_linspace, y_shallow, color="#fd99fe", label="shallow error line (?)", linestyle="--")
plt.plot(x_linspace, y_steep, color="#af2bbf", label="steep error line (?)", linestyle="--")

# plot the points with their error bars
plt.errorbar(x_values, y_values, yerr=yerrs, fmt="mx", label="???? (Domänenwissen)", capsize=5)

# prettify the graph
plt.grid(True, alpha=0.3)
# correct the bounds of the y axis
plt.ylim(bottom=0, top=2.5)

# labelling
plt.xlabel("Dicke in cm")
plt.ylabel("Zaehlrate in [hab die Einheit vergessen]")
plt.title("Guck mal coole Grafik oder")
plt.legend()

# Remap displayed y tick labels from log10-space back to linear-space values.
y_ticks = plt.yticks()[0]
# I'm only showing the values that are clean exponents of 10 (10**0 = 1, 10**1 = 10, 10**2 = 100 etc.)
# If you want janky in-between values (e.g. 10**1.25 ~ 17.78) you can remove the if clause
y_tick_labels = [f"{10 ** tick:.0f}" if tick.is_integer() else "" for tick in y_ticks]
plt.yticks(y_ticks, y_tick_labels)

plt.gca().set_facecolor("#ffe8f6")

# Also export the plot to a file named "plot.svg". Change this ideally to a more meaningful name xd
plt.savefig("plot.svg")

plt.show()
```