### Test 1
moves:
```
g1f3 d7d5 g2g3 c7c5 f1g2 b8c6 d2d4 e7e6 e1g1 g8f6 c2c4 f8e7 d4c5 e7c5 a2a3 d5c4 d1c2 e8g8 c2c4 c5d6 e2e4 c6e5 f3e5 d6e5 c4c2 c8d7 b1c3 d8c7 f1e1 a8d8 c1e3 d7c6 f2f4 e5c3 c2c3 f8e8 e3d4 c7e7 d4a7 d8c8 a7c5 e7c7 a1c1 f6d7 c5d4 e6e5 f4e5 d7e5 c1d1 c7e7 d4c5 e7g5 d1d6 c8d8 e1d1 d8d7 h2h3 d7d6 d1d6 h7h6 c5d4 g7g6 b2b4 g5e7 d4c5 e7g5
```
- go depth 6

```
do c5d4
do g5e7
do d4c5
do e7g5
```

- go again -> truncated pv with incorrect evals

> [!hint] PGN
> ```
> 1. Ng1f3 Pd7d5 2. Pg2g3 Pc7c5 3. Bf1g2 Nb8c6 4. Pd2d4 Pe7e6 5. O-O Ng8f6 6. Pc2c4 Bf8e7 7. Pd4xc5 Be7xc5 8. Pa2a3 Pd5xc4 9. Qd1c2 O-O 10. Qc2xc4 Bc5d6 11. Pe2e4 Nc6e5 12. Nf3xe5 Bd6xe5 13. Qc4c2 Bc8d7 14. Nb1c3 Qd8c7 15. Rf1e1 Ra8d8 16. Bc1e3 Bd7c6 17. Pf2f4 Be5xc3 18. Qc2xc3 Rf8e8 19. Be3d4 Qc7e7 20. Bd4xa7 Rd8c8 21. Ba7c5 Qe7c7 22. Ra1c1 Nf6d7 23. Bc5d4 Pe6e5 24. Pf4xe5 Nd7xe5 25. Rc1d1 Qc7e7 26. Bd4c5 Qe7g5 27. Rd1d6 Rc8d8 28. Re1d1 Rd8d7 29. Ph2h3 Rd7xd6 30. Rd1xd6 Ph7h6 31. Bc5d4 Pg7g6 32. Pb2b4 Qg5e7 33. Bd4c5 Qe7g5
> ```

### Test 2 (shorter but less verifyable)
moves:
```
d2d4 g8f6 c1g5 e7e6 e2e3 c7c5 b1d2 b7b6 d2e4 f8e7 g5f6 g7f6 d4c5 b6c5 e4d6 e7d6 d1d6 d8b6 e1c1 b6d6 d1d6 c8b7 g1e2 e8e7 d6d1 b8c6 e2f4 c6e5 f1e2 h8d8 h1e1 a8c8 a2a4 a7a5 e2b5 b7e4 f2f3 e4c6 c2c4 e5g6
```

- go depth 9
- undetected repetitions start creeping in from depth 7

```
do f4e2 
do g6e5
do e2f4
do e5g6
do f4e2
(do f3g4)d
```

### Case 3
```
Warning; PV continues after threefold repetition - move g8f8 from dev

Info; info depth 9 seldepth 15 score cp -132 nodes 31276 nps 5272116 time 5 tt 81 pv g8f8 b7c7 f8g8 c7b7 g8f8 b7c7 f8g8 c7b7 g8f8

Position; startpos

Moves; e2e4 c7c6 c2c4 d7d5 e4d5 c6d5 c4d5 g8f6 d1a4 b8d7 b1c3 g7g6 g2g3 f8g7 f1g2 e8g8 g1e2 d7b6 a4b5 a7a6 b5c5 c8f5 e1g1 a8c8 c5a3 f6d5 a3b3 e7e6 f1d1 f5d3 c3d5 d3e2 d1e1 e6d5 e1e2 d8d6 d2d3 a6a5 c1e3 c8e8 a1e1 e8e6 e3b6 d6b6 e2e6 b6b3 a2b3 f7e6 e1e6 f8d8 e6b6 g7b2 b6b7 b2c3 g2f3 d5d4 f3e4 d8d6 g1g2 h7h5 h2h4
```


## Spamming the Discord
Hi, we're having an issue concerning PV generation in combination with a Transposition Table when it comes to threefold repetitions/50 move rules. Basically: Since Zobrist hashing doesn't incorporate repetitions, the TT always yields the same best move. Since we're using the TT to cut off nodes, this results in the following scenario:
- say we have position A with a TT entry as so:
	- score: +100
	- best move: Qa1
	- bound: Exact
- say Qa1 leads to position B
- say also we've visited  position B twice already in the search tree
- when starting the search, the TT at depth 0, position A immediately goes "ah I know this one" and yields a score of +100 by means of Qa1

The only way I've found mitigating this is to prohibit TT-based cutoffs whenever the current position has already occurred - an approach I don't like because it still leads to incorrect PVs when the draw occurs at a higher depth, it only prevents the engine from 'blundering a threefold repetition' on its next move (when using TT walking as opposed to triangular PVs for PV generation (which we moved away from due to extremely truncated PV lines due to TT cutoffs)). - Do you guys know of any better solutions to this problem?
