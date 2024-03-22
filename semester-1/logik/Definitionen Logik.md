[[Relationen sind eine Teilmenge der Produktmenge]]
### [[Signatur]] $\Sigma = \set{F, P}$ 
> OOP Analogie: [[Interface]]
- $F$ ist Menge an _Funktionssymbolen_
- $P$ ist Menge an Prädikaten

### [[Struktur]]
> OOP Analogie: _Implementierung_ von [[Interface]]
- gehört zu einer [[Signatur]] $\Sigma = \set{F, P}$ 
- Enthält [[Universum]] $\Delta$ 
- Ordnet jedem [[Funktion|Funktionssymbol]] $f \in F$ eine [[Funktion]] und jedem [[Prädikat]] $p \in P$ eine [[Relation]] über $\Delta$ zu

### [[Interpretation]] 
> Macht eine logische Formel $\varphi$ entweder $true$ oder $false$
#### Aussagenlogik
- [[Funktion]] $I: V \rightarrow \mathbb{B}$ 
#### Prädikatenlogik
- ist eine [[Struktur]] für die [[Signatur]], die durch Formel gegeben ist
	==> $I = \set{\Delta, F_{\Delta}, P_{\Delta}}$ 

### [[Modell]] für $\varphi$ 
> [[Interpretation]], die $\varphi$ $true$ macht

- In _Prädikatenlogik_ entsprechend komplexer als in Aussagenlogik