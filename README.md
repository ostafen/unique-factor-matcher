# Efficient String Matching Based on a Two-Step Simulation of the Suffix Automaton [CIAA 2021]
Simone Faro and Stefano Scafiti

## Introduction
In this paper, we present a new general approach to the exact string matching algorithm based on a non-standard efficient  simulation  of  the suffix automaton of the pattern and give a specific efficient implementation of it. From our experimental results the new algorithm turnsout to be very efficient in practical cases scaling much better when thelength of the pattern increases, improving the search speed by nearly 10 times under suitable conditions.

## Source Code Information
This repository contains the official implementation of UFM exact string matching algorithm presented in \[1\].
The source code is intended to run inside the SMART string matching research tool \[2\] (SMART is available at https://github.com/smart-tool/smart).

## Experimental Results

 We compare the algorithm against the most efficient solutions known in the literature for the online exact string matching problem. Search speed, reported in GB/s, have been obtained on a genome sequence, a protein sequence and an English text. Best results have been bold faced.

### Genome Sequence

| m     | 32     | 64     | 128    | 256    | 512    | 1024   | 2,048  | 4,096  | 8,192  | 16,384 | 32,768 | 65,536 |
|-------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
| BNDM  |  2.82  |  2.81  |  2.82  |  2.79  |  2.81  |  2.91  |  2.89  |  2.89  |  2.84  |  2.91  |  2.92  |  2.84  |
| LBNDM |  1.54  |  1.72  |  1.90  |  0.83  |  0.19  |  0.2   |  0.22  |  0.24  |  0.24  |  0.26  | 0.25   |  0.25  |
| BXS   |  2.77  |  2.81  |  2.77  |  2.76  |  2.81  |  2.77  |  2.86  |  2.89  |  2.89  |  2.87  |  2.82  |  2.79  |
| FBNDM |  1.68  |  2.25  |  2.29  |  2.28  |  2.25  |  2.27  |  2.29  |  2.26  |  2.27  |  2.56  |  2.48  |  2.24  |
| BSDM  |  2.68  |  2.84  |  2.87  |  2.96  |  3.01  |  2.98  |  2.96  |  3.01  |  3.0   |  3.26  |  3.32  |  3.09  |
| UFM   |  2.84  |  3.19  |  3.37  |  3.41  |  **3.73**  |  **3.91**  |  **4.0**   |  **4.04**  |  **7.4**   |  **14.8**  |  **23.2**  |  **30.5**  |
| EPSM  |  **3.28**  |  **3.34**  |  **3.51**  |  **3.67**  |  3.70  |  3.73  |  3.81  |  3.81  |  4.17  |  5.19  |  5.25  |  4.61  |
| WFR   |  2.91  |  3.15  |  3.28  |  3.39  |  3.64  |  3.79  |  3.84  |  3.84  |  6.69  |  9.57  |  6.78  |  2.25  |
| TWFR  |  2.70  |  2.87  |  3.13  |  3.34  |  3.62  |  3.70  |  3.79  |  3.88  |  6.88  |  9.77  |  6.88  |  2.21  |

### Protein Sequence

| m     | 32     | 64     | 128    | 256    | 512    | 1024   | 2,048  | 4,096  | 8,192  | 16,384 | 32,768 | 65,536 |
|-------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
| BNDM  |  2.70  |  2.76  |  2.67  |  2.73  |  2.68  |  2.70  |  2.71  |  2.70  |  2.68  |  2.70  |  2.68  |  2.77  |
| LBNDM |  2.03  |  2.37  |  2.56  |  2.70  |  2.76  |  2.61  |  1.31  |  0.6   |  0.47  |  0.45  |  0.45  |  0.47  |
| BXS   |  2.67  |  2.70  |  2.67  |  2.70  |  2.67  |  2.70  |  2.65  |  2.68  |  2.63  |  2.64  |  2.63  |  2.61  |
| FBNDM |  2.27  |  2.57  |  2.70  |  2.65  |  2.70  |  2.71  |  2.68  |  2.70  |  2.70  |  2.64  |  2.67  |  2.67  |
| BSDM  |  2.71  |  2.87  |  2.98  |  2.98  |  2.98  |  3.01  |  3.01  |  3.01  |  3.0   |  2.98  |  3.03  |  3.07  |
| UFM   |  2.81  |  2.87  |  2.98  |  3.09  |  3.26  |  **3.49**  |  **3.51**  |  **3.49**  |  **6.6**   |  **12.2**  |  **21.2**  |  **28.7**  |
| EPSM  |  **2.91**  |  **3.03**  |  **3.15**  |  **3.32**  |  3.37  |  3.37  |  3.39  |  3.41  |  3.76  |  4.14  |  4.40  |  4.61  |
| WFR   |  2.73  |  2.94  |  3.03  |  3.19  |  3.26  |  3.46  |  3.49  |  3.51  |  6.10  |  10.61 |  12.85 |  5.25  |
| TWFR  |  2.82  |  2.94  |  3.07  |  3.19  |  3.32  |  3.44  |  3.51  |  3.51  |  6.10  |  10.61 |  12.85 |  5.31  |

### English Text

| m     | 32     | 64     | 128    | 256    | 512    | 1024   | 2,048  | 4,096  | 8,192  | 16,384 | 32,768 | 65,536 |
|-------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
| BNDM  |  2.63  |  2.56  |  2.63  |  2.6   |  2.57  |  2.57  |  2.57  |  2.61  |  2.58  |  2.56  |  2.52  |  2.52  |
| LBNDM |  1.74  |  2.16  |  2.42  |  2.58  |  2.73  |  2.73  |  2.42  |  1.68  |  1.08  |  0.79  |  0.65  |  0.58  |
| BXS   |  2.57  |  2.65  |  2.6   |  2.58  |  2.58  |  2.57  |  2.60  |  2.58  |  2.58  |  2.53  |  2.50  |  2.44  |
| FBNDM |  1.98  |  2.25  |  2.52  |  2.54  |  2.57  |  2.54  |  2.52  |  2.56  |  2.67  |  2.52  |  2.52  |  2.48  |
| BSDM  |  2.68  |  2.79  |  2.84  |  2.94  |  2.89  |  2.96  |  2.98  |  3.0   |  3.17  |  3.01  |  3.03  |  3.11  |
| UFM   |  2.63  |  2.77  |  2.91  |  3.03  |  3.32  |  3.39  |  3.46  |  3.54  |  **6.98**  |  **12.5**  |  **21.2**  |  **28.7**  |
| EPSM  |  **2.87**  |  **2.94**  |  **3.01**  |  **3.30**  |  **3.37**  |  3.34  |  3.34  |  3.37  |  4.00  |  4.21  |  4.65  |  4.93  |
| WFR   |  2.63  |  2.84  |  2.91  |  3.11  |  3.34  |  **3.44**  |  3.44  |  **3.62**  |  6.18  |  8.88  |  7.63  |  3.91  |
| TWFR  |  2.74  |  2.84  |  2.92  |  3.11  |  3.32  |  3.41  |  **3.49**  |  3.56  |  6.10  |  8.72  |  7.75  |  4.04  |

## References
[1] S. Faro and S. Scafiti, Efficient String Matching Based on a Two-Step Simulation of the Suffix Automaton, CIAA (2021).

[2] S. Faro, T. Lecroq, S. Borzi, S. D. Mauro, A. Maggio, The string matching algorithms research tool, in: Proceedings of the Prague Stringology Conference 2016, Prague Stringology Club, 2016, pp. 99-113.