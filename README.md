# Efficient String Matching Based on a Two-Step Simulation of the Suffix Automaton [CIAA 2021]
Simone Faro and Stefano Scafiti

## Introduction
In this paper, we present a new general approach to the exact string matching algorithm based on a non-standard efficient  simulation  of  the suffix automaton of the pattern and give a specific efficient implementation of it. From our experimental results the new algorithm turnsout to be very efficient in practical cases scaling much better when thelength of the pattern increases, improving the search speed by nearly 10 times under suitable conditions.

## Source Code Information
This repository contains the official implementation of UFM exact string matching algorithm presented in \[1\].
The source code is intended to run inside the SMART string matching research tool \[2\] (SMART is available at https://github.com/smart-tool/smart).

## Experimental Results

### Genome Sequence

| m     | 32     | 64     | 128    | 256    | 512    | 1024   | 2,048  | 4,096  | 8,192  | 16,384 | 32,768 | 65,536 |
|-------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
| BNDM  |  2.82  |  2.81  |  2.82  |  2.79  |  2.81  |  2.91  |  2.89  |  2.89  |  2.84  |  2.91  |  2.92  |  2.84  |
| LBNDM |  1.54  |  1.72  |  1.90  |  0.83  |  0.19  |  0.2   |  0.22  |  0.24  |  0.24  |  0.26  | 0.25   |  0.25  |
| BXS   |  2.77  |  2.81  |  2.77  |  2.76  |  2.81  |  2.77  |  2.86  |  2.89  |  2.89  |  2.87  |  2.82  |  2.79  |
| BSDM  |  2.68  |  2.84  |  2.87  |  2.96  |  3.01  |  2.98  |  2.96  |  3.01  |  3.0   |  3.26  |  3.32  |  3.09  |
| UFM   |  2.84  |  3.19  |  3.37  |  3.41  |  **3.73**  |  **3.91**  |  **4.0**   |  **4.04**  |  **7.4**   |  **14.8**  |  **23.2**  |  **30.5**  |
| EPSM  |  **3.28**  |  **3.34**  |  **3.51**  |  **3.67**  |  3.70  |  3.73  |  3.81  |  3.81  |  4.17  |  5.19  |  5.25  |  4.61  |
| WFR   |  2.91  |  3.15  |  3.28  |  3.39  |  3.64  |  3.79  |  3.84  |  3.84  |  6.69  |  9.57  |  6.78  |  2.25  |
| TWFR  |  2.70  |  2.87  |  3.13  |  3.34  |  3.62  |  3.70  |  3.79  |  3.88  |  6.88  |  9.77  |  6.88  |  2.21  |

## References
[1] S. Faro and S. Scafiti, Efficient String Matching Based on a Two-Step Simulation of the Suffix Automaton, CIAA (2021).

[2] S. Faro, T. Lecroq, S. Borzi, S. D. Mauro, A. Maggio, The string matching algorithms research tool, in: Proceedings of the Prague Stringology Conference 2016, Prague Stringology Club, 2016, pp. 99-113.