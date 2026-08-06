> Failover

1. Leader eines Clusters sendet alle ~150ms Heartbeats an Member
2. Wenn heartbeat failed:
	1. Member erhebt sich selbst zu Leader Candidate
	2. dann passiert voting
3. Followers auf veraltetem Stand werden einfach nicht gewählt

- [[Nachricht|Nachrichten]] sind nummeriert - Follower kümmern sich sich selbst darum, verpasste Nachrichten einzuholen
- "committed" [[Nachricht]] -> die Mehrheit der Knoten hat sie erhalten

### Terms
- Wahlen sind an Terms geknüpft
	- für jeden Term kann es nicht zwei Merheitsentschlüsse geben


