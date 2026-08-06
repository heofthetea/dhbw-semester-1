> [[Harmonisches MIttel]] aus [[Recall]] and [[Positive Predictive Value|Precision]]

[[Positive Predictive Value]], [[Recall|True Positive Rate]]

> [!hint]  **Harmonisches** Mittel - damit der Score gut ist, müssen **beide** Werte gut sein (sobald einer schlechter ist zieht es den Score sofort runter)


$$F_{1} = 2 \cdot \frac{PPV \cdot TPR}{PPV+TPR}$$
- random Umformung von Liebgott:
$$= \frac{2TP}{2TP+FP+FN}$$