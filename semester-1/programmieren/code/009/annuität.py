def berechne_annuitaet(darlehensbetrag, zinssatz):
    z = zinssatz
    A = (darlehensbetrag * z) / (1 - (1 + z))
    return A

while True:
	d = int(input("darlehen: "))
	z = int(input("zinssatz: "))
	print(berechne_annuitaet(d, z))
