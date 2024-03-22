[[Example Hamming-Code 16-bit]]
### Encoding
1. divide Message into 11 bit blocks
2. leave indices $\set{0, 1, 2, 4, 8}$ as correcton bits
3. place 11bit information in Order
4. Set [[Parity]] Bits accordingly

### Decoding
[[Refining Parity Checks]]
1. Narrow down where error can be by control group
2. If Error's location is determined: _correct by flipping bit_

![[Pasted image 20240216165516.png]]