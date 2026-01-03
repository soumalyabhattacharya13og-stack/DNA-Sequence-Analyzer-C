# DNA Sequence Analyzer (C)

A C-based bioinformatics program that performs basic DNA sequence analysis.
This project combines core biological concepts with programming in C.

---

## Features

- DNA sequence validation (A, T, G, C)
- Nucleotide counting
- GC content calculation
- Restriction enzyme motif detection:
  - EcoRI (GAATTC)
  - BamHI (GGATCC)
  - HindIII (AAGCTT)
- DNA to protein translation
- CSV output for Excel analysis

---

## Input

- DNA sequence via keyboard input
- Supports sequences up to ~1000 bp
- Case-insensitive input

Example:
```
ATGTTTGTTTTTCTTGTTTTAAGCTTGGATCCGAATTC
```

---

## Output

### Console Output
- Sequence length
- Base counts (A, T, G, C)
- GC percentage
- Motif positions
- Protein sequence

### Generated Files
- `sequence_stats.csv`
- `protein_sequence.csv`

---

## How to Compile and Run

### Offline (GCC)
```bash
gcc dna_analyzer.c -o dna_analyzer
./dna_analyzer
```

### Online Compiler
- Paste the code into an online C compiler
- Run and enter DNA sequence
- Download CSV files

---

## Project Structure

```
DNA-Sequence-Analyzer-C/
│
├── dna_analyzer.c
├── README.md
├── sample_dna.txt
├── sequence_stats.csv
└── protein_sequence.csv
```

---

## Biological Concepts Used

- GC content analysis
- Restriction enzyme recognition sites
- Genetic code and codon translation

---

## Academic Use

Suitable for:
- College mini-project
- Bioinformatics practicals
- Viva and lab evaluation
- Internship portfolio

---

## Author

Soumalya Bhattacharya  
Rupam Dilip Ghosh 
Biotechnology Student
