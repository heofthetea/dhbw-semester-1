> Bitgenauses Kopieren von dateien

```bash
dd -if=<input file> -of=<output file>
```

> [!hint] Derivative: `ddrescue`

## Additional parameters
- `bs`: block size

> [!warning] kopiert nur, macht nicht mehr
> - [[Zip compression algorithm|Compression]], [[Encryption]] oder spezielles forensisches Format wird nicht unterstützt
> - hat kein Error handling oder contiue-from-failed-state
# Alternativen
-  `dcfldd` und `dc3dd`

> [!warning] `dcfldd` hat seit 2006 keine commits mehr lol


