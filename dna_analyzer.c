#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 2000

// ------------------------------
// Genetic Code Translation
// ------------------------------
char translate_codon(char codon[]) {
    if(strcmp(codon,"ATG")==0) return 'M';
    if(strcmp(codon,"TTT")==0 || strcmp(codon,"TTC")==0) return 'F';
    if(strcmp(codon,"TTA")==0 || strcmp(codon,"TTG")==0) return 'L';
    if(strcmp(codon,"TAA")==0 || strcmp(codon,"TAG")==0 || strcmp(codon,"TGA")==0) return '*';
    if(strcmp(codon,"GTT")==0 || strcmp(codon,"GTC")==0 ||
       strcmp(codon,"GTA")==0 || strcmp(codon,"GTG")==0) return 'V';
    if(strcmp(codon,"GCT")==0 || strcmp(codon,"GCC")==0 ||
       strcmp(codon,"GCA")==0 || strcmp(codon,"GCG")==0) return 'A';
    return 'X'; // unknown
}

int main() {
    char dna[MAX];
    int A=0, T=0, G=0, C=0;

    printf("Enter DNA sequence:\n");
    fgets(dna, MAX, stdin);

    int len = strlen(dna);
    if(dna[len-1] == '\n') {
        dna[len-1] = '\0';
        len--;
    }

    // ------------------------------
    // Validate + Count bases
    // ------------------------------
    for(int i=0; i<len; i++) {
        dna[i] = toupper(dna[i]);

        if(dna[i]=='A') A++;
        else if(dna[i]=='T') T++;
        else if(dna[i]=='G') G++;
        else if(dna[i]=='C') C++;
        else {
            printf("❌ Invalid DNA base detected!\n");
            return 0;
        }
    }

    float gc = (G + C) * 100.0 / len;

    // ------------------------------
    // Console Output
    // ------------------------------
    printf("\n🧬 DNA ANALYSIS RESULTS\n");
    printf("----------------------\n");
    printf("Length: %d bp\n", len);
    printf("A: %d\nT: %d\nG: %d\nC: %d\n", A, T, G, C);
    printf("GC Content: %.2f%%\n", gc);

    // ------------------------------
    // Motif Search
    // ------------------------------
    char motifs[3][7] = {"GAATTC","GGATCC","AAGCTT"};
    char names[3][10] = {"EcoRI","BamHI","HindIII"};

    printf("\n🔍 Motifs Found:\n");
    for(int m=0; m<3; m++) {
        char *pos = dna;
        while((pos = strstr(pos, motifs[m])) != NULL) {
            printf("%s at position %ld\n", names[m], pos - dna + 1);
            pos++;
        }
    }

    // ------------------------------
    // DNA → Protein Translation
    // ------------------------------
    char protein[MAX] = "";
    char codon[4];
    codon[3] = '\0';

    for(int i=0; i<len-2; i+=3) {
        codon[0] = dna[i];
        codon[1] = dna[i+1];
        codon[2] = dna[i+2];

        char aa = translate_codon(codon);
        if(aa == '*') break;
        protein[strlen(protein)] = aa;
    }

    printf("\n🧪 Protein Sequence:\n%s\n", protein);

    // ------------------------------
    // Save CSV Files
    // ------------------------------
    FILE *stats = fopen("sequence_stats.csv", "w");
    fprintf(stats, "Metric,Value\n");
    fprintf(stats, "Length,%d\nA,%d\nT,%d\nG,%d\nC,%d\nGC%%,%.2f\n",
            len, A, T, G, C, gc);
    fclose(stats);

    FILE *prot = fopen("protein_sequence.csv", "w");
    fprintf(prot, "Protein Sequence\n%s\n", protein);
    fclose(prot);

    printf("\n📁 CSV files generated (Excel compatible)\n");

    return 0;
}
