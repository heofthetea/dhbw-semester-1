---
aliases:
  - IdP
---
> Ein zentraler [[Server]], der Nutzer Identitäten hält

- Kombination aus: Credential Pattern ([[Access Token]]) und [[Circle of Trust]]
- Identity Provider handelt [[Authentication]] ab
	- gibt [[Token|Tokens]] aus; [[OAuth 2.0]]/[[OIDC]]
- [[Resource|Ressourcen]] können in verschiedenen Domänen sein ([[Keycloak Realm|Realms]]) => die **vertrauen** dem [[Identity Provider]]
- [[Token]] wird [[Digital Signature|signiert]], steckt ein [[Certificate]] dahinter idR

![[Pasted image 20260320153043.png]]