- Problem: [[Interface]] austauschen führt zu breaking changes
	- Man will aber 100% availability ([[SLA]])
- **Lösung**: Zwei parallele Deployments
	- Durch [[Loadbalancer Service|Loadbalancing]] entscheiden wo eine Anfrage hingeht
- Enziel: Altes Interface ablösen


> [!warning] Stichwort: Initial Program Load (?)

