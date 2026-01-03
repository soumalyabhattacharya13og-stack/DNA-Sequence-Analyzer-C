# DNA Sequence Analyzer (C)

A C-based bioinformatics program that performs basic DNA sequence analysis.

## Features
- DNA sequence validation
- Nucleotide counting (A, T, G, C)
- GC content calculation
- Restriction enzyme motif detection (EcoRI, BamHI, HindIII)
- DNA to protein translation
- CSV output for Excel analysis

## Input
- DNA sequence via keyboard input

## Output
- sequence_stats.csv
- protein_sequence.csv

## How to Compile and Run
```bash
gcc dna_analyzer.c -o dna_analyzer
./dna_analyzer
