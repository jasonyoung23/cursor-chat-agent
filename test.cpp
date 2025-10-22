#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Circuit Analysis - Homework 3, Problem 1" << endl;
    cout << "==========================================" << endl << endl;
    
    // Given values
    double I_source1 = 10.0;  // 10A current source (upward/entering)
    double I_source2 = 2.0;   // 2A current source (downward/leaving)
    double R1 = 10.0;         // 10Ω resistor
    double R2 = 20.0;         // 20Ω resistor
    double R3 = 30.0;         // 30Ω resistor
    double R4 = 60.0;         // 60Ω resistor
    
    cout << "Given Circuit Elements:" << endl;
    cout << "  Current Source 1: " << I_source1 << " A (upward)" << endl;
    cout << "  Current Source 2: " << I_source2 << " A (downward)" << endl;
    cout << "  R1 = " << R1 << " Ω" << endl;
    cout << "  R2 = " << R2 << " Ω" << endl;
    cout << "  R3 = " << R3 << " Ω" << endl;
    cout << "  R4 = " << R4 << " Ω" << endl << endl;
    
    // Analysis:
    // All resistors are in parallel, connected between v_o (top) and ground (bottom)
    // Apply KCL at the top node (v_o):
    // Current entering = Current leaving
    // I_source1 = i1 + i2 + i3 + i4 + I_source2
    // Therefore: i1 + i2 + i3 + i4 = I_source1 - I_source2
    
    double I_total = I_source1 - I_source2;
    
    cout << "Analysis:" << endl;
    cout << "  Using KCL at node v_o:" << endl;
    cout << "  i1 + i2 + i3 + i4 = " << I_source1 << " A - " << I_source2 << " A = " << I_total << " A" << endl << endl;
    
    // Since all resistors are in parallel, they all have voltage v_o across them
    // Using Ohm's Law: i = v/R
    // i1 = v_o/R1, i2 = v_o/R2, i3 = v_o/R3, i4 = v_o/R4
    // Substituting into KCL equation:
    // v_o/R1 + v_o/R2 + v_o/R3 + v_o/R4 = I_total
    // v_o * (1/R1 + 1/R2 + 1/R3 + 1/R4) = I_total
    
    double G_eq = (1.0/R1) + (1.0/R2) + (1.0/R3) + (1.0/R4);  // Equivalent conductance
    double v_o = I_total / G_eq;
    
    cout << "  Equivalent conductance: 1/" << R1 << " + 1/" << R2 << " + 1/" << R3 << " + 1/" << R4 << " = " << G_eq << " S" << endl;
    cout << "  Therefore: v_o = " << I_total << " A / " << G_eq << " S = " << v_o << " V" << endl << endl;
    
    // Calculate individual currents using Ohm's Law
    double i1 = v_o / R1;
    double i2 = v_o / R2;
    double i3 = v_o / R3;
    double i4 = v_o / R4;
    
    // Display results
    cout << "RESULTS:" << endl;
    cout << "========" << endl;
    cout << fixed << setprecision(4);
    cout << "  v_o = " << v_o << " V" << endl;
    cout << "  i1  = " << i1 << " A" << endl;
    cout << "  i2  = " << i2 << " A" << endl;
    cout << "  i3  = " << i3 << " A" << endl;
    cout << "  i4  = " << i4 << " A" << endl << endl;
    
    // Verification using KCL
    double sum_currents = i1 + i2 + i3 + i4;
    cout << "Verification (KCL):" << endl;
    cout << "  i1 + i2 + i3 + i4 = " << sum_currents << " A" << endl;
    cout << "  Expected: " << I_total << " A" << endl;
    cout << "  Error: " << abs(sum_currents - I_total) << " A" << endl;
    
    return 0;
}