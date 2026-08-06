> Ist eine Einweg-[[Abbildung|Funktion]], die ein beliebiges [[Wort]] in ein [[Wort]] einer fixen Länge transformiert

$$h: \set{0, 1}^{*} \longrightarrow \set{0, 1}^{n}$$

1.  [[Kollisionsresistenz|Collision Resistance]]: Ein [[Tupel]] $(x, y)$ zu finden sodass $h(x) = h(y)$ sollte so [[Computational Hardness|hart]] wie möglich sein
2.  **Pre-image resistance**: Es existiert keine [[Abbildung]] $\overline{h}(y)$ sodass $\overline{h}(h(x)) = x$ => Es sollte unmöglich sein, $x$ aus $h(x)$ zurück zu gewinnen

> [!warning] Bei einer Kryptografischer [[Hash-Funktion]]: [[Kollisionsresistenz]] ist MANDATORY, und hohe [[Komplexität]] ist nichts schlechtest (schwereres Bruteforce)

> [!info] Muss auch einfach zu berechnen sein!! -> [[Konstante Laufzeit]] ideally

## Anwendung für [[Hash Map|Hash Maps]]
> [[Abbildung]] von [[semester-2/algorithmen/Schlüssel|Keys]] auf eine [[Teilmenge]] der Natürlichen Zahlen

- Wertebereich von $h$ muss:

  - deutlich größer sein als die tatsächliche Anzahl der [[semester-2/algorithmen/Schlüssel|Keys]]
  - deutlich kleiner als die Zahl der _möglichen_ Keys

- sollte möglichst gut streuen --> [[semester-2/algorithmen/Kollision]] unlikely
- Clustering sollte vermieden werden (wäre dann gleich scheiße wie sortiertes [[Array]])

> [!hint] Hier ist kryptografische Sicherheit (i.e. 2. Punkt oben) weniger relevant.

### Beispiel

- [[Modulo]]
- [[SHA-256]]
