#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

// Formats and displays a floating-point value with specified width and precision
void format_display(double value, int width, int decimal_places) {
    cout << setw(width) << fixed << setprecision(decimal_places) << value << endl;
}

// Applies a scaling operation to two values
template <typename T>
// It allows precise control over numeric display through width and decimal place parameters
void apply_scaling(T& primary, T& secondary, T scale_factor = 10) {
    T original_primary = primary;
    T original_secondary = secondary;
    // Combines addition, subtraction, and multiplication for value modification
    primary = (original_primary + original_secondary) * scale_factor;
    secondary = (original_primary - original_secondary) * scale_factor;
}

// Determines if a value falls within a specified interval
template <typename T>
bool within_interval(T target, T lower_bound, T upper_bound) {
    // Returns boolean result indicating whether the target is within the specified interval
    return (target >= lower_bound) && (target <= upper_bound);  
}

int main() {
    double sample_value = 456.7890;
    int display_width = 12, precision_digits = 3;

    // Demonstration of format_display function
    cout << "Formatted output demonstration:" << endl;
    format_display(sample_value, display_width, precision_digits);

    // Demonstration of apply_scaling function
    double x = 8, y = 4;
    cout << "Pre-scaling: x = " << x << ", y = " << y << endl;
    // Applies scaling transformation to the numeric values
    apply_scaling(x, y);
    cout << "Post-scaling: x = " << x << ", y = " << y << endl;

    return 0;
}