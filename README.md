# Efficient String Matching Based on a Two-Step Simulation of the Suffix Automaton [CIAA 2021]
Simone Faro and Stefano Scafiti

## Introduction
In this paper, we present a new general approach to the exact string matching algorithm based on a non-standard efficient  simulation  of  the suffix automaton of the pattern and give a specific efficient implementation of it. From our experimental results the new algorithm turnsout to be very efficient in practical cases scaling much better when thelength of the pattern increases, improving the search speed by nearly 10 times under suitable conditions.

## Source Code Information
This repository contains the official implementation of UFM exact string matching algorithm presented in \[1\].
The source code is intended to run inside the SMART string matching research tool \[2\] (SMART is available at https://github.com/smart-tool/smart).

## References
[1] S. Faro and S. Scafiti, Efficient String Matching Based on a Two-Step Simulation of the Suffix Automaton, CIAA (2021).

[2] S. Faro, T. Lecroq, S. Borzi, S. D. Mauro, A. Maggio, The string matching algorithms research tool, in: Proceedings of the Prague Stringology Conference 2016, Prague Stringology Club, 2016, pp. 99-113.